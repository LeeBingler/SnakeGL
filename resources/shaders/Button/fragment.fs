#version 330 core
out vec4 FragColor;

uniform vec3 bgColor;

void main()
{
    FragColor = vec4(bgColor, 1.0);
}
