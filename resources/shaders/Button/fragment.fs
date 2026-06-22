#version 330 core
out vec4 color;

uniform vec3 bgColor;

void main()
{
    color = vec4(bgColor, 1.0);
}
