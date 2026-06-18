#include "glm/detail/type_vec.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "main/OrthoCamera.hpp"
#include "main/Shader.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iterator>
#include <main/GUI/Snake.hpp>
#include <main/Core/Core.hpp>

Snake_node_t Snake::makeNewNode(float x, float y) {
  Snake_node_t node;

  glGenVertexArrays(1, &node.VAO);
  glGenBuffers(1, &node.VBO);
  glGenBuffers(1, &node.EBO);

  glBindVertexArray(node.VAO);

  glBindBuffer(GL_ARRAY_BUFFER, node.VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, node.EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  node.model = glm::mat4(1.0f);
  node.translate = glm::vec3(x, y, 0.0);

  return node;
}

Snake::Snake(glm::vec3 scale_game, std::array<int, 2> position_head) {
  scale = scale_game;
  snake_gui.push_back(makeNewNode(position_head[0], position_head[1]));
}

void Snake::update_matrices(std::list<struct Snake_part>& snake_core) {
  std::list<Snake_part_t>::iterator it_core = snake_core.begin();

  for (auto& node_gui : snake_gui) {
    Snake_part_t& node_core = *it_core;

    // update snake position
    node_gui.translate.y = node_core.position[0];
    node_gui.translate.x = node_core.position[1];

    // matrix update
    node_gui.model = glm::mat4(1.0f);
    node_gui.model = glm::scale(node_gui.model, scale);
    node_gui.model = glm::translate(node_gui.model, node_gui.translate);
    it_core++;
  }
}

void Snake::checkNewNode(std::list<struct Snake_part>& snake_core) {
  const unsigned int core_size = snake_core.size();
  const unsigned int gui_size = snake_gui.size();

  if (core_size <= gui_size)
    return;

  auto it_core = std::next(snake_core.begin(), gui_size);

  for (; it_core != snake_core.end(); it_core++) {
    Snake_node_t new_node = makeNewNode(it_core->position[1], it_core->position[0]);
    snake_gui.push_back(new_node);
  }
}

void Snake::draw(std::list<struct Snake_part>& snake_core, OrthoCamera& camera) {
  shader.use();
  checkNewNode(snake_core);
  update_matrices(snake_core);
  view = camera.getViewMatrix();
  projection = camera.getProjectionMatrix();

  for (auto& node : snake_gui) {
    shader.setMat4("model", node.model);
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);
    glBindVertexArray(node.VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  }
}

Snake::~Snake() {
  shader.deleteProgram();

  for (auto& node : snake_gui) {
    glDeleteVertexArrays(1, &node.VAO);
    glDeleteBuffers(1, &node.VBO);
    glDeleteBuffers(1, &node.EBO);
  }
}
