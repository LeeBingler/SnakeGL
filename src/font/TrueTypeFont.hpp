#pragma once

#include <map>
#include <string>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <main/Shader.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H

struct Character {
  unsigned int textureID; // ID handle of the glyph texture
  glm::ivec2 Size;        // Size of glyph
  glm::ivec2 Bearing;     // Offset from baseline to left/top of glyph
  long int Advance;       // Offset to advance to next glyph
};

class TrueTypeFont {
public:
  void RenderText(Shader& shader, std::string text, float x, float y, float scale, glm::vec3 color);
  TrueTypeFont(std::string fontPath);
  void destroyAll();

private:
  unsigned int nbCharList{128};
  unsigned int VAO, VBO;
  std::map<char, Character> Characters;
};
