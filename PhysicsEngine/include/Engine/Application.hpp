#pragma once
#include <Engine/Logger.hpp>
#include <Engine/Window.hpp>
#include <Platform/Window/Window.hpp>

namespace Engine {
extern void Init();
} // namespace Engine

int main(int argc, char **argv) {
  CORE_TRACE("Application started");
  auto window = Engine::Window::Create();
  window->Init({400, 400, "Hola mundo"});
  Engine::Init();
  return 0;
}