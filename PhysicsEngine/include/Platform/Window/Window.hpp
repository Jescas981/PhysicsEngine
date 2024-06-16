#pragma once
#include <Engine/Event/Event.hpp>
#include <Engine/Window.hpp>
#include <functional>

namespace Platform {
class Window {
public:
  virtual void Init(const Engine::WindowProps &props) = 0;
  virtual bool Running() const = 0;
  virtual ~Window() {}
  void SetEventListener(std::function<void(Engine::Event &event)> listener) {
    listener_ = listener;
  }

protected:
  std::function<void(Engine::Event &event)> listener_;
};
} // namespace Platform
