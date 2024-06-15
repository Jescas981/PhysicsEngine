#pragma once
#include <Engine/Window.hpp>

namespace Platform {
struct Window {
  virtual void Init(const Engine::WindowProps &props) = 0;
  ~Window() {}
};
} // namespace Platform
