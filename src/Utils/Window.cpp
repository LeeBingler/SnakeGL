#include <main/Window.hpp>

Window Window::sWindow;

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
  (void)window;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
  (void)window;

  Window::get()->setCursor(xpos, ypos);
}

void Window::createWindow(int width, int height) {
  window = glfwCreateWindow(width, height, "Snake GL", NULL, NULL);
  if (window == NULL) {
    return;
  }
  size.width = width;
  size.height = height;

  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // Track mouse movement
  glfwSetCursorPosCallback(window, mouse_callback);
}

Window::~Window() {
  glfwDestroyWindow(window);
}
