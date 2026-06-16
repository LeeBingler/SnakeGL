#include <main/OrthoCamera.hpp>

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
  return glm::lookAt(eye, target, up);
}

glm::mat4 OrthoCamera::getProjectionMatrix() const {
  return projection;
}

glm::mat4 OrthoCamera::getViewProjectionMatrix() const {
  return getProjectionMatrix() * getViewMatrix();
}

void OrthoCamera::setTarget(glm::vec3 new_target) {
  target = new_target;
}

void OrthoCamera::setEye(glm::vec3 new_eye) {
  eye = new_eye;
}

glm::mat4 OrthoCamera::updateProjectionMatrix(float left, float right, float bottom, float top,
                                              float near, float far) {
  projection = glm::ortho(left, right, bottom, top, near, far);
  return projection;
}
