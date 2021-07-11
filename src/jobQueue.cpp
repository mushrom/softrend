#include <softrend/jobQueue.hpp>

using namespace softrend;

jobQueue::jobQueue(unsigned concurrency) {
#ifdef __EMSCRIPTEN__
	// TOOO: some way to do background tasks on webgl, it's JS after all

#else
	//for (unsigned i = 0; i < concurrency; i++) {
	for (unsigned i = 0; i < concurrency; i++) {
		workers.push_back(std::thread(&jobQueue::worker, this));
	}
#endif
	//workers.push_back(std::thread(&jobQueue::worker, this));
	//workers.push_back(std::thread(&jobQueue::worker, this));
}

jobQueue::~jobQueue() {
	running = false;
	workers.clear();

	/*
	for (auto& thr : workers) {
		// detached threads should be stopped once jobQueue is deleted, I think
		thr.detach();
	}
	*/
}

std::future<bool> jobQueue::addAsync(std::function<bool()> job) {
#ifdef __EMSCRIPTEN__
	return addDeferred(std::packaged_task<bool()>(job));
#else
	return addAsync(std::packaged_task<bool()>(job));
#endif
}

std::future<bool> jobQueue::addDeferred(std::function<bool()> job) {
	return addDeferred(std::packaged_task<bool()>(job));
}

std::future<bool> jobQueue::addAsync(std::packaged_task<bool()> job) {
	std::lock_guard<std::mutex> g(mtx);
	auto fut = job.get_future();
#ifdef __EMSCRIPTEN__
	deferredJobs.push_back(std::move(job));
#else
	asyncJobs.push_back(std::move(job));
	waiters.notify_one(); // wake up a thread, if any are available
#endif
	return fut;
}

std::future<bool> jobQueue::addDeferred(std::packaged_task<bool()> job) {
	std::lock_guard<std::mutex> g(mtx);
	auto fut = job.get_future();
	deferredJobs.push_back(std::move(job));
	return fut;
}

void jobQueue::runDeferred(void) {
	std::lock_guard<std::mutex> g(mtx);

	for (auto& job : deferredJobs) {
		job();
	}

	deferredJobs.clear();
}

bool jobQueue::runSingleDeferred(void) {
	std::lock_guard<std::mutex> g(mtx);
	bool ran = false;

	if (!deferredJobs.empty()) {
		auto& job = deferredJobs.front();
		job();

		deferredJobs.pop_front();
		ran = true;
	}

	return ran;
}

void jobQueue::worker(void) {
	// TODO: loop condition
	while (running) {
		auto job = getAsync();
		job();
	}

	std::terminate();
}

void jobQueue::sync(void) {
	/*
	std::unique_lock<std::mutex> slock(mtx);
	waiters.wait(slock, [this]{ return asyncJobs.empty(); });
	*/

	//while (available != workers.size() && !asyncJobs.empty()) {
	// XXX: need to figure out how to block here
	while (true) {
		{
			std::unique_lock<std::mutex> slock(mtx);
			if  (available == workers.size() && asyncJobs.empty()) 
				return;
		}

		std::this_thread::yield();
		//std::this_thread::sleep_for(std::chrono::microseconds(1000));
	}
}

#include <iostream>
#include <SDL.h>
std::packaged_task<bool()> jobQueue::getAsync(void) {
	std::unique_lock<std::mutex> slock(mtx);

	available++;
	if (asyncJobs.empty()) {
		// TODO: debug statements hurt performance
#if 0
		SDL_Log("[job queue] got here, thread %lu waiting for job",
			std::hash<std::thread::id>{}(std::this_thread::get_id()));
#endif

		waiters.wait(slock, [this]{ return !asyncJobs.empty(); });
	}

#if 0
	SDL_Log("[job queue] (empty: %d) got here, thread %lu",
		asyncJobs.empty(),
		std::hash<std::thread::id>{}(std::this_thread::get_id()));
#endif

	auto job = std::move(asyncJobs.front());
	asyncJobs.pop_front();
	available--;
	return job;
}
