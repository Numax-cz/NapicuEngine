cmake_minimum_required(VERSION 3.18)
project(OpenGL)

find_package(OpenGL REQUIRED)
add_subdirectory(external/glad)
add_subdirectory(external/glfw)
add_subdirectory(external/imgui)



file(GLOB_RECURSE SOURCES src/*.cpp src/**/*.cpp )
add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES})


target_include_directories(${PROJECT_NAME}
        PUBLIC external/glfw/include
        PUBLIC external/glad/include
        PUBLIC external/imgui/)


target_link_directories(${PROJECT_NAME}
        PRIVATE external/glad/
        PRIVATE external/glfw/
        PRIVATE external/imgui/
        )

target_link_libraries(${PROJECT_NAME} opengl32 glfw IMGUI GLAD )