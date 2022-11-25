#pragma once
#include <imgui.h>


namespace Napicu{
    class EditorView {

    private:
        static ImVec2 getViewportSize();

        static ImVec2 getCenterViewportPosition(ImVec2 aspect);

    public:
        static void imgui();
    };

}


