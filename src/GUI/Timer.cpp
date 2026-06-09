#include <main/GUI/Timer.hpp>

Timer::Timer() {
  deltaTime = 0.0;
  lastFrame = 0.0;
}

void Timer::updateDelta() {
  float currentFrame = glfwGetTime();
  deltaTime = currentFrame - lastFrame;
  lastFrame = currentFrame;
}
