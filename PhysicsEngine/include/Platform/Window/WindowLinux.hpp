#pragma once
#include <Platform/Window/Window.hpp>

namespace Platform {

class WindowLinux : public Window {
  void Init(const Engine::WindowProps &props) override;
};
} // namespace Platform