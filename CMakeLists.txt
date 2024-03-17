cmake_minimum_required(VERSION 3.22)

project(math_lib VERSION 1.0.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# [ variables.. ]
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
set(PROJECT_EXECUTABLE "math_lib")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# [ option.. ]
option(ENABLE_WARNINGS "Enable To Add Warnings To A Target." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable To Treat Warnings As Errors." OFF)
option(GEN_GRAPHVIZ_PNG "Generate Dependencies Graph." ON)
option(ENABLE_LTO "Enable To Add Link Time Optimization." ON)
option(ENABLE_SANITIZE_ADDR "Enable Address Sanitize." ON)
option(ENABLE_SANITIZE_UNDEF "Enable Undefined Sanitize." ON)
option(ENABLE_SANITIZE_LEAK "Enable Leak Sanitize (Gcc/Clang Only)." OFF)
option(ENABLE_SANITIZE_THREAD "Enable Thread Sanitize (Gcc/Clang Only)." OFF)

# [ includes.. ]
include(cpm)
include(variables)

if(ENABLE_WARNINGS)
    include(warnings)
endif()

if(ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizer)
    add_sanitizer_flags()
endif()

if(ENABLE_LTO)
    include(lto)
endif()

add_subdirectory(includes)
add_subdirectory(src)