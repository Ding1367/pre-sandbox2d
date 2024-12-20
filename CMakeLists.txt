cmake_minimum_required(VERSION 3.29)
project(sandbox2d CXX)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(GL_SILENCE_DEPRECATION)

include_directories("./include")

find_library(GLFW_LIBRARY NAMES glfw glfw3)
find_path(GLFW_INCLUDE_DIR
        NAMES GLFW/glfw3.h
        HINTS /usr/local/include /opt/glfw/include
        PATH_SUFFIXES GLFW
)

if(NOT GLFW_INCLUDE_DIR OR NOT GLFW_LIBRARY)
    message(FATAL_ERROR "GLFW not found!")
endif()

include_directories(${GLFW_INCLUDE_DIR})
link_libraries(${GLFW_LIBRARY})

add_library(sandbox2d STATIC
        src/object.cpp
        include/object.hpp
        src/ndc_plane.cpp
        include/ndc_plane.hpp
        src/geometry.cpp
        include/geometry.hpp
        src/engine.cpp
        include/engine.hpp
        include/glutil.hpp
        src/part.cpp
        include/part.hpp
        src/camera.cpp
        include/camera.hpp
)

set_target_properties(sandbox2d PROPERTIES
    OUTPUT_NAME "core")