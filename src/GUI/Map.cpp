#include <main/GUI/Map.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/detail/type_vec.hpp>

Map::Map(std::vector<std::vector<int>>& map) : map(map) {}

Map::Map(glm::vec3 scale_game, std::vector<std::vector<int>>& map) : map(map) {
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

  double width = scale_game.x * map[0].size();
  double height = scale_game.y * map.size();

  model = glm::mat4(1.0f);
  model = glm::translate(
      model, glm::vec3((width - scale_game.x) / 2.0f, (height - scale_game.y) / 2.0f, 0.0f));
  model = glm::scale(model, glm::vec3(width, height, 1.0f));
  shader.use();
}

void Map::draw(OrthoCamera& camera) {
  shader.use();
  view = camera.getViewMatrix();
  projection = camera.getProjectionMatrix();

  shader.setMat4("model", model);
  shader.setMat4("view", view);
  shader.setMat4("projection", projection);
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Map::destroyAll() {
  shader.deleteProgram();
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
}
