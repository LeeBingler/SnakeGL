#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
  static Window* get() {
    return &sWindow;
  }
  GLFWwindow* getWindow() {
    return window;
  };
  ~Window();
  void createWindow();
  static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

private:
  GLFWwindow* window;
  static Window sWindow;
};
