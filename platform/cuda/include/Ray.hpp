#pragma once
#ifndef __CUDA_RAY_HPP__
#define __CUDA_RAY_HPP__

#include "renderer.hpp"
#include "maths/operation.hpp"
#include <cuda_runtime.h>
#include <stdio.h>

#define PRINT(v) printf(" [ %f, %f, %f ] \n", v.x, v.y, v.z)

namespace Renderer
{
    namespace Cuda
    {
        struct Ray
        {
            Vec3 origin;
            Vec3 direction;
            __device__
            Ray(const Vec3& origin, const Vec3& direction):
                origin(origin), direction(direction)
            {}
            Ray() = default;
            __device__
            Vec3 at(float t) const {
                return origin+t*direction;
            }
        };
    } // namespace Cuda
} // namespace Renderer


#endif