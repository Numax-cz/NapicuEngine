cmake_minimum_required(VERSION 3.18)
project(OpenGL)

find_package(OpenGL REQUIRED)

include_directories(
        PUBLIC external/glfw/include
        PUBLIC external/glad/include
        PUBLIC external/imgui/
)

add_library(IMGUI
        external/imgui/imgui.cpp
        external/imgui/imgui_widgets.cpp
        external/imgui/imgui_tables.cpp
        external/imgui/imgui_draw.cpp
        external/imgui/backends/imgui_impl_glfw.cpp
        external/imgui/backends/imgui_impl_opengl3.cpp
        )

add_subdirectory(external/glad)
add_subdirectory(external/glfw)
#add_subdirectory(external/imgui)
add_subdirectory(external/glm)
add_subdirectory(external/stb)

file(GLOB_RECURSE SOURCES src/*.cpp src/**/*.cpp )
add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES})


target_include_directories(${PROJECT_NAME}
        PUBLIC external/glfw/include
        PUBLIC external/glad/include
        PUBLIC external/stb/include
        PUBLIC external/imgui/
        PUBLIC external/imgui/backends/
        PUBLIC external/glm/
        )


target_link_directories(${PROJECT_NAME}
        PRIVATE external/glad/
        PRIVATE external/glfw/
        PRIVATE external/imgui/backends/
        PRIVATE external/imgui/
        PRIVATE external/glm/
        PRIVATE external/stb/
        )

target_link_libraries(${PROJECT_NAME} opengl32 glfw IMGUI GLAD glm STB)