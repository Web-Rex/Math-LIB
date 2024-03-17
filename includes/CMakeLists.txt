# ----- [ Public ]
file(GLOB_RECURSE PUBLIC_HEADERS CMAKE_CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/public/include/*.h")
file(GLOB_RECURSE PUBLIC_SOURCES CMAKE_CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/public/src/*.cpp")

add_library(public ${PUBLIC_SOURCES} ${PUBLIC_HEADERS})
target_include_directories(public PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/public/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/public/src
    # ${CMAKE_BINARY_DIR}/configured/include
)
# target_link_libraries(public PRIVATE libglew_static)