#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <main/renderLoop.hpp>
#include <main/Window.hpp>

// behing call when the window is resize

// GLFW init
int initGLFW() {
  if (!glfwInit()) {
    std::cout << "Failed to initialize GLFW" << std::endl;
    return -1;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  return 0;
}

int main() {
  if (initGLFW()) {
    std::cout << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  Window* window = Window::get();
  window->createWindow();

  if (window->getWindow() == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -2;
  }

  // GLAD: load openGL function pointer
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    glfwTerminate();
    return -3;
  }

  glViewport(0, 0, 800, 600);
  renderLoop();

  glfwTerminate();
  return 0;
}
