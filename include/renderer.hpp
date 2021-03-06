#pragma once

#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "renderError.hpp"

namespace Renderer
{
    enum class RenderEnv
    {
        UNDEFINE,
        CPU,
        CPU_OPTIMIZED,
        CUDA
    };

    struct RenderConfig {
        int width = 960;
        int height = 540;
        bool gamma = true;
        int depth = 8;
        int sampleNums = 512;
    };

    ErrorCode init(RenderEnv env);

    using id_t = unsigned int;

    struct alignas(16) Vec3
    {
        union
        {
            struct
            {
                float x, y, z;
            };
            struct
            {
                float r, g, b;
            };
            float d[3];
        };
        
    };
    
    ErrorCode render(Vec3** pixels);

    namespace Material
    {
        id_t createLambertain(id_t texture);
        id_t createEmitted(id_t texture,
            float  luminance,
            int    luminanceAttenuation,
            float  luminanceDistance);
        id_t createGlass(id_t texture, float n);
        id_t createSpecular(id_t texture, float glossy);
        id_t createPhong(id_t texture, const Vec3& ks, float shiness);
    };

    namespace Object
    {
        id_t createSphere(const Vec3& position, float radius, id_t material);
        id_t createTriangle(const Vec3& p1, const Vec3& p2, const Vec3& p3, const Vec3& anchor ,id_t material);
    };

    namespace Texture{
        id_t createSolid(const Vec3& rgb);
    };

    struct Camera
    {
        float vfov;
        float aspect;
        float focusDistance;
        float aperture;
        Vec3 position;
        Vec3 lookat;
    };

    void setCamera(float vfov, float aspect, float focusDistance,
        float aperture, Vec3 position, Vec3 lookat);

    void setRenderConfig(int width, int height, int depth = 8, int sampleNums = 512, bool gamma = true);

};

#endif