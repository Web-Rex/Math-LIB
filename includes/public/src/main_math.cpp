#include "main_math.h"

//  --- [ MATH-2 ]
math_lib::vec2::vec2() : x(1.0f), y(1.0f) {}
math_lib::vec2::vec2(float xy) : x(xy), y(xy) {}
math_lib::vec2::vec2(float x_, float y_) : x(x_), y(y_) {}
math_lib::vec2::~vec2() {}

math_lib::vec2 math_lib::vec2::operator+(vec2 xy)
{
    return vec2(x + xy.x, y + xy.y);
}
math_lib::vec2 math_lib::vec2::operator-(vec2 xy)
{
    return vec2(x - xy.x, y - xy.y);
}
math_lib::vec2 math_lib::vec2::operator*(int val)
{
    return vec2(x * val, y * val);
}
math_lib::vec2 math_lib::vec2::operator+=(vec2 xy)
{
    x += xy.x;
    y += xy.y;

    return *this;
}
math_lib::vec2 math_lib::vec2::operator-=(vec2 xy)
{
    x -= xy.x;
    y -= xy.y;

    return *this;
}
math_lib::vec2 math_lib::vec2::operator*=(int val)
{
    x *= val;
    y *= val;

    return *this;
}

//  --- [ MATH-3 ]
math_lib::vec3::vec3() : x(1.0f), y(1.0f), z(1.0f) {}
math_lib::vec3::vec3(float xyz) : x(xyz), y(xyz), z(xyz) {}
math_lib::vec3::vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
math_lib::vec3::~vec3() {}

math_lib::vec3 math_lib::vec3::operator+(vec3 xyz)
{
    return vec3(x + xyz.x, y + xyz.y, z + xyz.z);
}
math_lib::vec3 math_lib::vec3::operator-(vec3 xyz)
{
    return vec3(x - xyz.x, y - xyz.y, z - xyz.z);
}
math_lib::vec3 math_lib::vec3::operator*(int val)
{
    return vec3(x * val, y * val, z * val);
}

math_lib::vec3 math_lib::vec3::operator+=(vec3 xyz)
{
    x += xyz.x;
    y += xyz.y;
    z += xyz.z;

    return *this;
}
math_lib::vec3 math_lib::vec3::operator-=(vec3 xyz)
{
    x -= xyz.x;
    y -= xyz.y;
    z -= xyz.z;

    return *this;
}
math_lib::vec3 math_lib::vec3::operator*=(int val)
{
    x *= val;
    y *= val;
    z *= val;

    return *this;
}

//  --- [ NORMALIZE ]
int math_lib::normalize(vec2 xy)
{
    return std::sqrt(std::abs(std::pow(xy.x, 2) + std::pow(xy.y, 2)));
}
int math_lib::normalize(vec3 xyz)
{
    return std::sqrt(std::abs(std::pow(xyz.x, 2) + std::pow(xyz.y, 2) + std::pow(xyz.z, 2)));
}

//  --- [ DOT-PRODUCT ]
int math_lib::dotP(vec2 xy_0, vec2 xy_1)
{
    return (xy_0.x * xy_1.x) + (xy_0.y * xy_1.y);
}
int math_lib::dotP(vec3 xyz_0, vec3 xyz_1)
{
    return (xyz_0.x * xyz_1.x) + (xyz_0.y * xyz_1.y) + (xyz_0.z * xyz_1.z);
}

//  --- [ VECTOR-PROJECTION ]
math_lib::vec2 math_lib::vectorPRJ(vec2 xy_0, vec2 xy_1)
{
    int dot = dotP(xy_0, xy_1);
    int nom = normalize(xy_1);

    return xy_1 * (dot / nom);
}
math_lib::vec3 math_lib::vectorPRJ(vec3 xyz_0, vec3 xyz_1)
{
    int dot = dotP(xyz_0, xyz_1);
    int nom = normalize(xyz_1);

    return xyz_1 * (dot / nom);
}