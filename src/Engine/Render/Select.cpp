#include "Select.h"
#include "../window.h"


namespace Napicu {

    Select::Select(int width, int height) {
        if(!this->init(width, height)){
            Napicu::Console::Error("(SelectTexture) Texture selecting failed");
        }
    }

    bool Select::init(int width, int height) {
        glGenFramebuffers(1, &this->fboID);

        glBindFramebuffer(GL_FRAMEBUFFER, this->fboID);

        glGenTextures(1, &this->selectedTextureID);
        glBindTexture(GL_TEXTURE_2D, this->selectedTextureID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height,
                     0, GL_RGB, GL_FLOAT, nullptr);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                               GL_TEXTURE_2D, this->selectedTextureID, 0);

        glEnable(GL_TEXTURE_2D);
        glGenTextures(1, &this->dTexture);
        glBindTexture(GL_TEXTURE_2D, this->dTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, width, height,
                     0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
                               GL_TEXTURE_2D, this->dTexture, 0);


        glReadBuffer(GL_NONE);
        glDrawBuffer(GL_COLOR_ATTACHMENT0);

        if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) return false;

        glBindTexture(GL_TEXTURE_2D, 0);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        return true;
    }

    int Select::read(int x, int y) {
        glBindFramebuffer(GL_READ_FRAMEBUFFER, this->fboID);
        glReadBuffer(GL_COLOR_ATTACHMENT0);

        float pxs[3] = {};

        glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &pxs);

        return (int)(pxs[0]) - 1;
    }

    void Select::enable() {
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, this->fboID);
    }

    void Select::disable() {
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
    }
}