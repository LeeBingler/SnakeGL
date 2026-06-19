#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class State {
public:
  virtual bool enter() = 0;
  virtual bool exit() = 0;

  virtual void handleEvent(GLFWwindow* window) = 0;
  virtual void update() = 0;
  virtual void render() = 0;

  virtual ~State() {};
};
