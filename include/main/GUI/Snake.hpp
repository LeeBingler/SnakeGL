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

  Snake();
  void draw(std::list<struct Snake_part> &head);
  void update();
  void deleteSelf();

private:
  void setModel();
  void setMatrix();
};
