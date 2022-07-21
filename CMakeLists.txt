cmake_minimum_required(VERSION 3.18)
project(OpenGL)

add_subdirectory(glfw/)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")
add_executable(${PROJECT_NAME} ${SOURCES})


target_include_directories(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
