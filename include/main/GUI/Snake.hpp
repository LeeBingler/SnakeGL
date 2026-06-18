#pragma once

#include <glm/detail/type_vec.hpp>
#include <main/Shader.hpp>
#include <main/OrthoCamera.hpp>
#include <list>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

typedef struct Snake_node {
  unsigned int VAO, VBO, EBO;
  glm::mat4 model;
  int modelLoc;
  glm::vec3 translate;
} Snake_node_t;

class Snake {
public:
  // Model
  Shader shader =
      Shader("resources/shaders/Snake/vertex.vs", "resources/shaders/Snake/fragment.fs");
  glm::mat4 projection, view;
  int projLoc, viewLoc;
  glm::vec3 scale;

  std::list<Snake_node_t> snake_gui;
  float vertices[12] = {
      0.5f,  0.5f,  0.0f, // top right
      0.5f,  -0.5f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.0f, // bottom left
      -0.5f, 0.5f,  0.0f  // top left
  };
  unsigned int indices[6] = {
      0, 1, 3, // first Triangle
      1, 2, 3  // second Triangle
  };

  Snake(glm::vec3 scale_game, std::array<int, 2> position_head);
  ~Snake();

  void draw(std::list<struct Snake_part>& snake_core, OrthoCamera& camera);
  void update_matrices(std::list<struct Snake_part>& snake_core);

private:
  void setMatrix(GLFWwindow* window);
  Snake_node_t makeNewNode(float x, float y);
  void checkNewNode(std::list<struct Snake_part>& snake_core);
};
