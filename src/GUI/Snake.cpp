#include "glm/detail/type_vec.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <main/GUI/Snake.hpp>
#include <main/Core/Core.hpp>

#include <iostream>

void Snake::setModel() {
  constexpr float vertices[] = {
      0.5f,  0.5f,  0.0f, // top right
      0.5f,  -0.5f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.0f, // bottom left
      -0.5f, 0.5f,  0.0f  // top left
  };
  constexpr unsigned int indices[] = {
      0, 1, 3, // first Triangle
      1, 2, 3  // second Triangle
  };

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
}

void Snake::setMatrix(GLFWwindow* window) {
  int width, height = 0;
  glfwGetWindowSize(window, &width, &height);

  model = glm::mat4(1.0f);

  view = glm::mat4(1.0f);
  view = glm::translate(view, glm::vec3(0.0f, static_cast<float>(height), -1.0f));

  projection =
      glm::ortho(0.0f, static_cast<float>(width), 0.0f, static_cast<float>(height), 0.1f, 100.0f);
  translate = glm::vec3(0.0, 0.0, 0.0);

  scale = glm::vec3(width / 15.0, height / 17.0, 1.0f);
}

Snake::Snake(GLFWwindow* window) {
  setModel();
  setMatrix(window);
}

Snake::Snake() { return; }

void Snake::update_matrices(std::list<struct Snake_part>& head) {
  // update snake position
  Snake_part_t node = head.front();
  setTranslate2D(node.position[0], -node.position[1]);

  // matrix update
  model = glm::mat4(1.0f);
  model = glm::scale(model, scale);
  model = glm::translate(model, translate);

  shader.setMat4("model", model);
  shader.setMat4("view", view);
  shader.setMat4("projection", projection);
}

void Snake::setTranslate2D(float x, float y) {
  translate.x = x;
  translate.y = y;
}

void Snake::draw(std::list<struct Snake_part>& head) {
  shader.use();

  update_matrices(head);
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Snake::deleteSelf() {
  shader.deleteProgram();
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
}
