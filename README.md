A software rasterizer! Intended to be a testbed for my own learning, but in 
theory it could be useful for general (light) 3D rendering.

Features:
- Multithreaded, tile-based renderer
- Fully asyncronous, can handle geometry processing and drawing for multiple
  rendering pipelines simultaneously without blocking
- Uses GCC-style vector extensions for portable simd (TODO: avx-512-specific paths)
- Portable to anything with a C++20 compiler and access to a raw framebuffer
- Fully header-based (Rephrasing "is templated" as a feature...)
- Z-buffer for depth testing

(TODO: more info, screenshots, docs)
