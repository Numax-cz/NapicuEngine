#include "Grid.h"
#include <glm/vec2.hpp>
#include "../window.h"
#include "../Utils/Config.h"
#include "../Render/Draw.h"

namespace Napicu{

    void Grid::update(double delta_time) {
        glm::vec2 cameraPosition = Napicu::Window::current_scene->getCamera()->getPosition();

        int fX = ((int)(cameraPosition.x / Napicu::Config::GRID_WIDTH ) - 1) * Napicu::Config::GRID_HEIGHT;
        int fY = ((int)(cameraPosition.y / Napicu::Config::GRID_HEIGHT) - 1) * Napicu::Config::GRID_HEIGHT;

        int numVerticalLines = (int)((Napicu::Config::CAMERA_PROJECTION_SIZE_X * Napicu::Window::current_scene->getCamera()->getZoomLevel()) / Napicu::Config::GRID_WIDTH) + 2;
        int numHorizontalLines = (int)((Napicu::Config::CAMERA_PROJECTION_SIZE_Y * Napicu::Window::current_scene->getCamera()->getZoomLevel()) / Napicu::Config::GRID_HEIGHT) + 2;

        int height = (int)(Napicu::Config::CAMERA_PROJECTION_SIZE_Y  * Napicu::Window::current_scene->getCamera()->getZoomLevel()) * Napicu::Config::GRID_HEIGHT * 2;
        int width = (int)(Napicu::Config::CAMERA_PROJECTION_SIZE_X  * Napicu::Window::current_scene->getCamera()->getZoomLevel()) + Napicu::Config::GRID_WIDTH * 2;

        int maxLines = std::max(numVerticalLines, numHorizontalLines);

        for(int i = 0; i < maxLines; i++){
            int x = fX + (Napicu::Config::GRID_WIDTH * i);
            int y = fY + (Napicu::Config::GRID_HEIGHT * i);

            if(i < numVerticalLines){
                Napicu::Draw::addLine(glm::vec2(x, fY),
                                      glm::vec2(x, fY + height));
            }

            if(i < numHorizontalLines){
                Napicu::Draw::addLine(glm::vec2(fX, y),
                                      glm::vec2(fX + width, y));
            }
        }

    }
}