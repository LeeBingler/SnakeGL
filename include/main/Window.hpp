#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct Cursor {
  double xPos = 0.0f;
  double yPos = 0.0f;
};

struct Size {
  int width = 0;
  int height = 0;
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

  Size size = {0, 0};

  ~Window();
  void createWindow(int width, int height);
  static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

private:
  GLFWwindow* window;
  static Window sWindow;
  Cursor cursor = {0.0, 0.0};
};
