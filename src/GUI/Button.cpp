#include "glm/gtc/matrix_transform.hpp"
#include "main/Window.hpp"
#include <main/GUI/Button.hpp>

void Button::destroyAll() {
  shaderBg.deleteProgram();
  shaderFont.deleteProgram();

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
}

Button::Button(std::string s, TrueTypeFont* f, float x, float y, float scale)
    : string(s), font(f), x(x), y(y), scale(scale), onPress(nullptr) {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  float left = x;
  float right = x + width;
  float bottom = y;
  float top = y + height;

  float bgVertices[12] = {
      left,  top,    0.0f, // top-left
      right, top,    0.0f, // top-right
      right, bottom, 0.0f, // bottom-right
      left,  bottom, 0.0f  // bottom-left
  };
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(bgVertices), bgVertices);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
}

Button::Button(std::string s, TrueTypeFont* f, float x, float y, float scale,
               std::function<void()> func = nullptr)
    : string(s), font(f), x(x), y(y), scale(scale), onPress(func) {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  const float WIDTH_BTN = 160.0f;
  const float HEIGHT_BTN = 50.0f;

  float left = x;
  float right = x + WIDTH_BTN;
  float bottom = y;
  float top = y + HEIGHT_BTN;

  float bgVertices[12] = {
      left,  top,    0.0f, // top-left
      right, top,    0.0f, // top-right
      right, bottom, 0.0f, // bottom-right
      left,  bottom, 0.0f  // bottom-left
  };
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(bgVertices), bgVertices);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
}

void Button::update() {
  Window* win = Window::get();
  Cursor cursor = win->getCursor();
  Size size = win->size;

  float mx = (float)cursor.xPos;
  float my = (float)size.height - (float)cursor.yPos; // flip Y

  isHovered = mx >= x && mx <= x + width && my >= y && my <= y + height;

  isPressed = glfwGetMouseButton(win->getWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

  // fire once, on the frame the click starts, only if it starts over the button
  if (isHovered && isPressed && !wasPressed && onPress)
    onPress();

  wasPressed = isPressed;
}

void Button::draw() {
  Size size = Window::get()->size;
  projection = glm::ortho(0.0f, (float)size.width, 0.0f, (float)size.height);

  // draw background FIRST
  shaderBg.use();
  shaderBg.setMat4("projection", projection);
  shaderBg.setVec4("bgColor", glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));

  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  // draw text ON TOP, centered inside the button
  if (font) {
    shaderFont.use();
    const float PADDING = 10.0f;
    float textX = x + PADDING;
    float textY = y + 5.0f; // vertically centered on baseline
    font->RenderText(shaderFont, string, textX, textY, scale, glm::vec3(1.0f, 1.0f, 1.0f));
  }
}
