#include <main/GUI/Button.hpp>
#include <iostream>
#include <main/States/MenuState.hpp>

#include <main/States/ExitState.hpp>
#include <main/States/GameState.hpp>
#include <main/StateManager.hpp>
#include <main/Window.hpp>

MenuState::MenuState() {}
MenuState MenuState::sMenuState;

MenuState::~MenuState() {}

MenuState* MenuState::get() {
  return &sMenuState;
}

bool MenuState::enter() {
  texturesButtons.emplace();
  texturesButtons->push_back(Texture2D("resources/sprite/play_button.png"));
  texturesButtons->push_back(Texture2D("resources/sprite/level_button.png"));
  texturesButtons->push_back(Texture2D("resources/sprite/quit_button.png"));

  for (auto& texture : *texturesButtons) {
    texture.setParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
    texture.setParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
    texture.setParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    texture.setParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    texture.loadTexture(GL_RGB, GL_RGBA, GL_UNSIGNED_BYTE);
  }

  Size size = Window::get()->size;
  projection =
      glm::ortho(0.0f, static_cast<float>(size.width), 0.0f, static_cast<float>(size.height));

  shaderSpriteRenderer.emplace("resources/shaders/Sprite/vertex.vs",
                               "resources/shaders/Sprite/fragment.fs");
  shaderSpriteRenderer->use();
  shaderSpriteRenderer->setMat4("projection", projection);
  shaderSpriteRenderer->setInt("image", 0);
  if (shaderSpriteRenderer)
    spriteRenderer.emplace(*shaderSpriteRenderer);

  font.emplace("resources/font/aileron.regular.otf");

  TrueTypeFont* fontPtr = &font.value();
  play.emplace(" PLAY", fontPtr, 325.0, 300.0, 1.0);
  level.emplace("LEVEL", fontPtr, 325.0, 200.0, 1.0);
  quit.emplace(" QUIT", fontPtr, 325.0, 100.0, 1.0);

  return true;
}

bool MenuState::exit() {
  if (texturesButtons) {
    for (auto& e : *texturesButtons) {
      e.deleteTexture();
    }
  }

  if (spriteRenderer)
    spriteRenderer->destroyAll();

  if (shaderSpriteRenderer)
    shaderSpriteRenderer->deleteProgram();

  if (font)
    font->destroyAll();

  if (play)
    play->destroyAll();
  if (level)
    level->destroyAll();
  if (quit)
    quit->destroyAll();
  return true;
}

void MenuState::handleEvent(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    StateManager* state = StateManager::get();
    state->setNextState(ExitState::get());
    return;
  }
}

void MenuState::update() {
  std::cout << Window::get()->getCursor().xPos << " " << Window::get()->getCursor().yPos
            << std::endl;
  if (play)
    play->update();
  if (level)
    level->update();
  if (quit)
    quit->update();
}

void MenuState::render() {
  int i = 0;
  for (auto& texture : *texturesButtons) {
    if (i == 0) {
      spriteRenderer->drawSprite(texture, glm::vec2(10.0f, 300.0f), glm::vec2(300.0f, 100.0f));
    }
    ++i;
  }

  if (play)
    play->draw();
  if (level)
    level->draw();
  if (quit)
    quit->draw();
}
