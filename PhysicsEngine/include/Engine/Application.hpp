#pragma once
#include <Engine/Event/Event.hpp>
#include <Engine/Logger.hpp>
#include <Engine/Window.hpp>
#include <Platform/Window/Window.hpp>

namespace Engine {
extern void Init();
extern void Update();
extern void OnEvent(Event &e);
} // namespace Engine

int main(int argc, char **argv) {
  CORE_TRACE("Application started");
  auto window = Engine::Window::Create();
  window->Init({400, 400, "Hola mundo"});
  window->SetEventListener(Engine::OnEvent);
  Engine::Init();
  while (window->Running()) {
    Engine::Update();
  }
  return 0;
}