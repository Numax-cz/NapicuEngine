#pragma once
#include "GLFW/glfw3.h"

namespace Napicu{
    struct Config{
        inline const static int GRID_WIDTH = 40;
        inline const static int GRID_HEIGHT = 40;

        inline const static int CAMERA_PROJECTION_SIZE_X = 1920;
        inline const static int CAMERA_PROJECTION_SIZE_Y = 1080;

        //***********
        //LEVE_EDITOR
        //***********
        inline const static float LEVEL_EDITOR_CAMERA_DRAG_SPEED = 30.0f;
        inline const static int LEVEL_EDITOR_CAMERA_DRAG_KEY = GLFW_MOUSE_BUTTON_MIDDLE;

    };
}