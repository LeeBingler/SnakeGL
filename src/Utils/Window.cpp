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

void Window::createWindow() {
  window = glfwCreateWindow(800, 600, "Snake GL", NULL, NULL);
  if (window == NULL) {
    return;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // Track mouse movement
  glfwSetCursorPosCallback(window, mouse_callback);
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

Window::~Window() {
  glfwDestroyWindow(window);
}
