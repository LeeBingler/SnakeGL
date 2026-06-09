#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Timer {
public:
  float deltaTime;
  float lastFrame;

  Timer();
  void updateDelta();
};
