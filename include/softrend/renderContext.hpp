#pragma once
#include <softrend/jobQueue.hpp>

namespace softrend {

template<typename T>
concept Renderable = requires(T a) {
	// vertex attribute format requires a mix function
	// (also requires a T::vertexAttr())
	mix(typename T::vertexAttr(), typename T::vertexAttr(), 0.5f);

	// need a depth and color buffer
	a.buffers.color;
	a.buffers.depth;
};

template <typename V, typename U, template <typename, typename, typename> typename S>
struct renderContext {
	renderContext(jobQueue& j, framebuffer<uint32_t> *c, framebuffer<float> *d)
		: jobs(j), buffers(c, d) {};

	using vertexAttr = V;
	using geomOutTri = std::array<V, 3>;
	using Framebuffers = fbPair<uint32_t, float>;
	//using vertexShader = perspectiveVertexShader<vertexAttr>;
	using uniformType = U;
	using shaders = S<vertexAttr, uniformType, Framebuffers>;

	jobQueue& jobs;
	Framebuffers buffers;
	// XXX
	using Bins = std::vector<int>;
	using Geobuf = std::vector<geomOutTri>;

	// TODO: lockless
	std::mutex mtx;
	// std::list because references remain valid after inserting
	// elements, std::vector references will be invalidated after the
	// underlying storage is resized
	// since this is just used for keeping track of resources it's no problem,
	// the code works with the references directly
	std::list<Geobuf> geometryBuf;
	std::list<Bins> bins;
	std::list<U> uniformBuffers;

	Geobuf& allocGeobuf(void) {
		std::unique_lock<std::mutex> slock(mtx);

		geometryBuf.push_back({});
		return geometryBuf.back();
	}

	Bins& allocBins(void) {
		std::unique_lock<std::mutex> slock(mtx);

		bins.push_back({});
		return bins.back();
	}

	U& allocUniforms(void) {
		std::unique_lock<std::mutex> slock(mtx);

		uniformBuffers.push_back(U());
		return uniformBuffers.back();
	}

	/*
	Geobuf& allocGeobuf(void);
	Bins& allocBins(void);
	*/

	void sync(void) {
		jobs.sync();
		{
			std::unique_lock<std::mutex> slock(mtx);
			geometryBuf.clear();
			bins.clear();
			uniformBuffers.clear();
		}
	}
};

// namespace softrend
}
