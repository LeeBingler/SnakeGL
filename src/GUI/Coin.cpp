#include <list>
#include <main/GUI/Coin.hpp>

Coin::Coin(std::vector<std::array<int, 2>> coin_position, glm::vec3 scale_game) {
  scale = scale_game;
  for (auto position : coin_position) {
    coin_gui.push_back(makeNewCoin(position[1], position[0]));
  }
}

Coin::~Coin() {
  shader.deleteProgram();

  for (auto& node : coin_gui) {
    glDeleteVertexArrays(1, &node.VAO);
    glDeleteBuffers(1, &node.VBO);
    glDeleteBuffers(1, &node.EBO);
  }
}

void Coin::updateCoinGUI(std::vector<std::array<int, 2>> coin_position) {
  std::list<Coin_node_t>::iterator it_gui = coin_gui.begin();

  for (auto position : coin_position) {
    Coin_node_t& coin_gui = *it_gui;

    coin_gui.translate.y = position[0];
    coin_gui.translate.x = position[1];
    coin_gui.model = glm::mat4(1.0);
    coin_gui.model = glm::scale(coin_gui.model, scale);
    coin_gui.model = glm::translate(coin_gui.model, coin_gui.translate);

    it_gui++;
  }
}

void Coin::draw(std::vector<std::array<int, 2>> coin_position, OrthoCamera camera) {
  shader.use();
  updateCoinGUI(coin_position);
  glm::mat4 view = camera.getViewMatrix();
  glm::mat4 projection = camera.getProjectionMatrix();

  for (Coin_node_t& coin : coin_gui) {
    shader.setMat4("model", coin.model);
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);
    glBindVertexArray(coin.VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  }
}

Coin_node_t Coin::makeNewCoin(int x, int y) {
  Coin_node_t node;

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
