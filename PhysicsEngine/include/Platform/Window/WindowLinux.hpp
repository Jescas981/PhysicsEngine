#pragma once
#include "Engine/Window.hpp"
#include <Platform/Window/Window.hpp>

namespace Platform {

struct RawWindow;

class WindowLinux : public Window {
public:
  void Init(const Engine::WindowProps &props) override;
  bool Running() const override;
  void SetEventListener(std::function<void(Engine::Event &)> listener) override;
  void Update() const override;

private:
  std::shared_ptr<RawWindow> raw_;
};
} // namespace Platform