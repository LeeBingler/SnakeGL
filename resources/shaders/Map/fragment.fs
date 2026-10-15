#version 330 core
in vec2 uv;
out vec4 FragColor;

uniform vec2 size_map;

void main() {
    vec2 cell = uv * size_map;

    // distance to the nearest cell border, in pixels
    vec2 d = abs(fract(cell - 0.5) - 0.5) / fwidth(cell);
    float dist = min(d.x, d.y);

    float lineWidth = 1.0;
    float line = 1.0 - min(dist / lineWidth, 1.0);

    vec3 background = vec3(1.0, 0.0, 0.0);
    vec3 lineColor  = vec3(0.4, 0.0, 0.0);

    FragColor = vec4(mix(background, lineColor, line), 1.0);
}
