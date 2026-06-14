#include "glm/detail/type_vec.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "main/Shader.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iterator>
#include <main/GUI/Snake.hpp>
#include <main/Core/Core.hpp>

void Snake::setMatrix(GLFWwindow* window) {
  int width, height = 0;
  glfwGetWindowSize(window, &width, &height);

  view = glm::mat4(1.0f);
  view = glm::translate(view, glm::vec3(0.0f, static_cast<float>(height), -1.0f));

  projection =
      glm::ortho(0.0f, static_cast<float>(width), 0.0f, static_cast<float>(height), 0.1f, 100.0f);

  scale = glm::vec3(width / 15.0, height / 17.0, 1.0f);
}

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

Snake::Snake(GLFWwindow* window) {
  setMatrix(window);
  snake_gui.push_back(makeNewNode(0.0, 0.0));
}

void Snake::update_matrices(std::list<struct Snake_part>& snake_core) {
  std::list<Snake_part_t>::iterator it_core = snake_core.begin();

  // update snake position
  for (auto& node_gui : snake_gui) {
    Snake_part_t& node_core = *it_core;

    node_gui.translate.x = node_core.position[0];
    node_gui.translate.y = -node_core.position[1];

    it_core++;
  }

  // matrix update
  for (auto& node : snake_gui) {
    node.model = glm::mat4(1.0f);
    node.model = glm::scale(node.model, scale);
    node.model = glm::translate(node.model, node.translate);
  }
}

void Snake::checkNewNode(std::list<struct Snake_part>& snake_core) {
  const unsigned int core_size = snake_core.size();
  const unsigned int gui_size = snake_gui.size();

  if (core_size <= gui_size)
    return;

  auto it_core = std::next(snake_core.begin(), gui_size);

  for (; it_core != snake_core.end(); it_core++) {
    Snake_node_t new_node = makeNewNode(it_core->position[0], -it_core->position[1]);
    snake_gui.push_back(new_node);
  }
}

void Snake::draw(std::list<struct Snake_part>& snake_core) {
  shader.use();
  checkNewNode(snake_core);
  update_matrices(snake_core);

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
