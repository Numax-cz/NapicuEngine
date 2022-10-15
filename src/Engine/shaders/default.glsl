#shader vertex

#version 460 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec4 aColor;
//layout (location=2) in vec2 aTexCords;

uniform mat4 uProjection;

out vec4 fColor;
//out vec2 vTexCords;

void main() {
    fColor = aColor;
    //vTexCords = aTexCords;
    //gl_Position = uProjection  * vec4(aPos, 1.0);
    gl_Position = uProjection *  vec4(aPos, 1.0);
}

#shader fragment
#version 460 core

in vec4 fColor;
//in vec2 vTexCords;
out vec4 color;

//uniform sampler2D texSampler;

void main(){
    //vec4 texColor = texture(texSampler, vTexCords);
    color = fColor;
}