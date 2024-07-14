cmake_minimum_required(VERSION 3.5.0)
project(glfw-hello VERSION 0.1.0 LANGUAGES C CXX)

find_package(glfw3 3.4 REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(glfw-hello main.cpp src/glad.c)
target_include_directories(glfw-hello PUBLIC include)
target_link_libraries(glfw-hello glfw)
target_compile_features(glfw-hello PUBLIC cxx_std_23)