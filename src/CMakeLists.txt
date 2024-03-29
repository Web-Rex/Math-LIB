add_executable(${PROJECT_EXECUTABLE} "./main.cpp" "./main.h")
target_link_libraries(${PROJECT_EXECUTABLE} PRIVATE public)
target_include_directories(${PROJECT_EXECUTABLE} PRIVATE  ${CMAKE_BINARY_DIR}/configured/include)

# [ Enable Warnings ]
if(${ENABLE_WARNINGS})
    ADD_WARNINGS_TO_TARGET(
        TARGET
        ${PROJECT_EXECUTABLE}
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS}
    )
endif()

# [ Enable LTO ]
if(${ENABLE_LTO})
    ADD_LTO_TO_TARGET(
        TARGET
        ${PROJECT_EXECUTABLE}
        ENABLE
        ON
    )
endif()

# [ Enable Graphviz ]
if(GEN_GRAPHVIZ_PNG)
    find_program(GRAPHVIZ dot)

    if(GRAPHVIZ)
        add_custom_target(graphviz
            COMMAND ${CMAKE_COMMAND} "--graphviz=dep-graph/foo.dot" .
            COMMAND dot -Tpng dep-graph/foo.dot -o dep-graph/foo.png
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        )
    else()
        set(ERROR "Graphviz is required to access this target.")
    endif()
endif()