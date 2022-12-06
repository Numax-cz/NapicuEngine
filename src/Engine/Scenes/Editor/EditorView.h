#pragma once
#include <imgui.h>


namespace Napicu{
    class EditorView {

    private:
        ImVec2 getViewportSize();

        ImVec2 getCenterViewportPosition(ImVec2 aspect);

    public:
        void imgui();
    };

}


