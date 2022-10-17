#shader vertex
#version 460 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec4 aColor;
layout (location=2) in vec2 aTexCords;
layout (location=3) in float aTexId;

uniform mat4 uProjection;

out vec4 fColor;
out vec2 fTexCords;
out float fTexId;

void main() {
    fColor = aColor;
    fTexCords = aTexCords;
    fTexId= aTexId;
    //gl_Position = uProjection  * vec4(aPos, 1.0);
    gl_Position = uProjection *  vec4(aPos, 1.0);
}

#shader fragment
#version 460 core

in vec4 fColor;
in vec2 fTexCords;
in float fTexId;

out vec4 color;

uniform sampler2D texSampler[8];

void main(){

    if(fTexId > 0){
        int id = int(fTexId);
        //color = fColor * texture(texSampler[id], fTexCords);
        color = texture(texSampler[id], fTexCords);
    }else color = fColor;
}