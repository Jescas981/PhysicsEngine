#pragma once
#include <Engine/Event/Event.hpp>
#include <Engine/Window.hpp>
#include <functional>

namespace Platform {
struct Window {
  virtual void Init(const Engine::WindowProps &props) = 0;
  virtual bool Running() const = 0;
  virtual void
  SetEventListener(std::function<void(Engine::Event &event)> listener) = 0;
  virtual ~Window() {}
};
} // namespace Platform
