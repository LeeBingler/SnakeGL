#include "main/Window.hpp"
#include <iostream>
#include <main/GUI/Button.hpp>

void Button::destroyAll() {
  shaderBg.deleteProgram();
  shaderFont.deleteProgram();

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
}

Button::Button(std::string s, TrueTypeFont* f, float x, float y, float scale)
    : string(s), font(f), x(x), y(y), scale((scale)) {
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

  model = glm::mat4(1.0f);
}

void Button::update() {
  Cursor cursor = Window::get()->getCursor();

  std::cout << cursor.xPos << " " << cursor.yPos << std::endl;
}

void Button::draw() {
  projection = glm::ortho(0.0f, static_cast<float>(800), 0.0f, static_cast<float>(600));

  // draw background
  shaderFont.use();
  shaderFont.setMat4("projection", projection);
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  // draw font
  if (font)
    font->RenderText(shaderFont, string, x, y, scale, glm::vec3(1.0, 1.0, 1.0));
}
