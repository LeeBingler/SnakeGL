#version 330 core
layout (location = 0) in vec3 aPos;

out vec2 uv;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    uv = aPos.xy + 0.5;   // -0.5..0.5  ->  0..1
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
