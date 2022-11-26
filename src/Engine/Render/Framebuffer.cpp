#include "Framebuffer.h"
#include "../window.h"

namespace Napicu{

    Framebuffer::Framebuffer(int width, int height) {
        glGenFramebuffers(1, &this->fboID);

        glBindFramebuffer(GL_FRAMEBUFFER, this->fboID);

        this->texture = new Napicu::Texture(width, height);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, this->texture->getTextureID(), 0);


        unsigned int rboID;
        glGenFramebuffers(1, &rboID);
        glBindRenderbuffer(GL_RENDERBUFFER, rboID);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT32, width, height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rboID);

        if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
            Napicu::Console::Error("FrameBuffer is not complete");
        }

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void Framebuffer::bind(){
        glBindFramebuffer(GL_FRAMEBUFFER, this->fboID);

    }

    void Framebuffer::unbind(){
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

    }

    unsigned int Framebuffer::getFboId() const {
        return this->fboID;
    }

    unsigned int Framebuffer::getTextureID() {
        return this->texture->getTextureID();
    }


}