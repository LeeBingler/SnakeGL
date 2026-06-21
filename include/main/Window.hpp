#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct Cursor {
  double xPos = 0.0f;
  double yPos = 0.0f;
};

class Window {
public:
  static Window* get() {
    return &sWindow;
  }
  GLFWwindow* getWindow() {
    return window;
  };

  Cursor& getCursor() {
    return cursor;
  };

  void setCursor(double x, double y) {
    cursor.xPos = x;
    cursor.yPos = y;
  }

  ~Window();
  void createWindow();
  static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

private:
  GLFWwindow* window;
  static Window sWindow;
  Cursor cursor = {0.0, 0.0};
};
