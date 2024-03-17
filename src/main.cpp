#include "main.h"

int main()
{
    int val{2};
    math_lib::vec2 vec2_0(1.0f, 2.0f), vec2_1(2.0f, 1.0f);
    // math_lib::vec3 vec3_0(1.0f, 2.0f, 1.0f), vec3_1(2.0f, 1.0f, 1.0f);

    math_lib::vec2 new_vec2 = vec2_0 * val;

    std::cout << " \n";
    std::cout << "dot-P: " << math_lib::dotP(vec2_0, vec2_1) << std::endl;
    // std::cout << "x: " << new_vec2.x << " y: " << new_vec2.y << std::endl;
    // std::cout << "x: " << (vec3_0 * val).x << " y: " << (vec3_0 * val).y << " z: " << (vec3_0 * val).z << std::endl;
    // std::cout << "nom: " << math_lib::normalize(vec2_0) << std::endl;
    std::cout << " \n";
    return 0;
}
