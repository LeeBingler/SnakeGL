#include "glm/detail/type_vec.hpp"
#include <main/OrthoCamera.hpp>

OrthoCamera::OrthoCamera() {
  projection = glm::ortho(-100.0, 100.0, -100.0, 100.0, 0.1, 100.0);
}

OrthoCamera::OrthoCamera(float left, float right, float bottom, float top, float near, float far) {
  this->left = left;
  this->right = right;
  this->top = top;
  this->bottom = bottom;
  this->near = near;
  this->far = far;

  projection = glm::ortho(left, right, bottom, top, near, far);
}

glm::mat4 OrthoCamera::getViewMatrix() const {
  return glm::lookAt(glm::vec3(position.x, position.y, 1.0), glm::vec3(position.x, position.y, 0.0),
                     up);
}

glm::mat4 OrthoCamera::getProjectionMatrix() const {
  return projection;
}

glm::mat4 OrthoCamera::getViewProjectionMatrix() const {
  return getProjectionMatrix() * getViewMatrix();
}

void OrthoCamera::setPosition(glm::vec2 new_position) {
  position = new_position;
}

void OrthoCamera::setPosition(float x, float y) {
  position = glm::vec2(x, y);
}

glm::mat4 OrthoCamera::updateProjectionMatrix(float left, float right, float bottom, float top,
                                              float near, float far) {
  projection = glm::ortho(left, right, bottom, top, near, far);
  return projection;
}
