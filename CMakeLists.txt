cmake_minimum_required(VERSION 3.18)
project(OpenGL)

add_subdirectory(glad/src)
add_subdirectory(glfw/)
find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES})


target_include_directories(${PROJECT_NAME} PUBLIC glfw PUBLIC glad/include)
target_link_directories(${PROJECT_NAME} PRIVATE glad/src)



target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_gl_LIBRARY} PUBLIC glfw)