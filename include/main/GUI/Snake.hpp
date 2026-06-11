#pragma once

#include <main/Shader.hpp>
#include <list>

class Snake {
public:
  // Model
  Shader shader = Shader("resources/shaders/Snake/vertex.vs",
                         "resources/shaders/Snake/fragment.fs");
  unsigned int VAO, VBO, EBO;
  glm::mat4 projection, view, model;
  int projLoc, viewLoc, modelLoc;
  glm::vec3 scale;
  glm::vec3 translate;

  Snake();
  void draw(std::list<struct Snake_part>& head);
  void update();
  void deleteSelf();

  void setTranslate2D(float x, float y);
  void setScale2D(float x, float y);

private:
  void setModel();
  void setMatrix();
};
