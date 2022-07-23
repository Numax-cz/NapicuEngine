cmake_minimum_required(VERSION 3.18)
project(OpenGL)

add_subdirectory(glfw/)
find_package(OpenGL REQUIRED)

file(GLOB SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")
add_executable(${PROJECT_NAME} ${SOURCES})


target_include_directories(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_gl_LIBRARY} PUBLIC glfw)