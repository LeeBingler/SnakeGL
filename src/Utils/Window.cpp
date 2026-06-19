#include <main/Window.hpp>

Window Window::sWindow;

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
  (void)window;
}

void Window::createWindow() {
  window = glfwCreateWindow(800, 600, "Snake GL", NULL, NULL);
  if (window == NULL) {
    return;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

Window::~Window() {
  glfwDestroyWindow(window);
}
