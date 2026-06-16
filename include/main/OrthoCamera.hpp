#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/detail/type_vec.hpp>
#include <glm/detail/type_mat.hpp>
#include <glm/gtc/matrix_transform.hpp>

class OrthoCamera {
public:
  OrthoCamera(float left, float right, float bottom, float top, float near, float far);

  float left, right, bottom, top, near, far;

  glm::mat4 getViewMatrix() const;
  glm::mat4 getProjectionMatrix() const;
  glm::mat4 getViewProjectionMatrix() const;

  glm::mat4 updateProjectionMatrix(float left, float right, float bottom, float top, float near,
                                   float far);

  void setTarget(glm::vec3 new_target);
  void setEye(glm::vec3 new_Eye);

private:
  glm::vec3 target{0.0, 0.0, 0.0};
  glm::vec3 eye{0.0, 0.0, 1.0};
  glm::vec3 up{0.0, 1.0, 0.0};
  glm::mat4 projection;
};
