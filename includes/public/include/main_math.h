#pragma once
#include <cmath>

namespace math_lib
{
    struct vec2
    {
        // public:
        float x, y;

        vec2();
        vec2(float xy);
        vec2(float x, float y);

        ~vec2();

        vec2 operator+(vec2 xy);
        vec2 operator-(vec2 xy);
        vec2 operator*(int val);

        vec2 operator+=(vec2 xy);
        vec2 operator-=(vec2 xy);
        vec2 operator*=(int val);
    };
    struct vec3
    {
        // public:
        float x, y, z;

        vec3();
        vec3(float xyz);
        vec3(float x, float y, float z);

        ~vec3();

        vec3 operator+(vec3 xyz);
        vec3 operator-(vec3 xyz);
        vec3 operator*(int val);

        vec3 operator+=(vec3 xyz);
        vec3 operator-=(vec3 xyz);
        vec3 operator*=(int val);
    };

    int normalize(vec2 xy);
    int normalize(vec3 xyz);

    int dotP(vec2 xy_0, vec2 xy_1);
    int dotP(vec3 xyz_0, vec3 xyz_1);

    vec2 vectorPRJ(vec2 xy_0, vec2 xy_1);
    vec3 vectorPRJ(vec3 xyz_0, vec3 xyz_1);
}