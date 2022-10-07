#pragma once


#ifndef OPENGL_LEVELEDITOR_H
#define OPENGL_LEVELEDITOR_H
#include "Scene.h"


namespace Napicu{

    class LevelEditor : public Napicu::Scene{

    private:
//        Napicu::Shader* shader = new Napicu::Shader("src/Engine/shaders/default.glsl");
//        Napicu::Texture* texture = new Napicu::Texture("src/Engine/imgs/bird.png");
//
//        Napicu::Object* test = new Napicu::Object("Object");
//
//
//
//        float vertexArray[36] = {
//                //Position                      //Color
//                 0.5f,0.5f, 0.0f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
//                0.5f,-0.5f, 0.0f,     1.0f, 1.0f, 0.0f,   1.0f, 0.0f,
//                 -0.5f, -0.5f, 0.0f,    1.0f, 0.0f, 1.0f,   0.0f, 0.0f,
//                -0.5f,0.5f,0.0f,     1.0f, 1.0f, 0.0f,     0.0f, 1.0f
//
//        };
//
//        int elementArray[6] = {
//                0,1,3,
//                1,2,3
//        };


    public:
        LevelEditor() : Napicu::Scene() {

        };

        void update(double delta_time) override;
        void init() override;

    };
}


#endif //OPENGL_LEVELEDITOR_H
