#pragma once

namespace Napicu {

    class Select {
    private:
        unsigned int selectedTextureID, dTexture, fboID;
    public:
        Select(int width, int height);

        bool init(int width, int height);

        void enable();

        void disable();

        int read(int x, int y);
    };

}