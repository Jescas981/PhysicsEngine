#pragma once
#include <Engine/Event/Event.hpp>
#include <Engine/Logger.hpp>
#include <Engine/Window.hpp>
#include <Platform/Window/Window.hpp>

namespace Engine {
class Application {
public:
  virtual void Init() {}

  virtual void Update() {}

  virtual void OnEvent(Event &e) {}

  virtual ~Application() {}
};
} // namespace Engine

#define APPLICATION(classname)                                                 \
  int main(int argc, char **argv) {                                            \
    CORE_TRACE("Application started");                                         \
    auto window = Engine::Window::Create();                                    \
    window->Init({400, 400, "Hola mundo"});                                    \
    classname app = classname();                                               \
    app.Init();                                                                \
    window->SetEventListener(                                                  \
        std::bind(&classname::OnEvent, &app, std::placeholders::_1));          \
    while (window->Running()) {                                                \
      app.Update();                                                            \
      window->Update();                                                         \
    }                                                                          \
    return 0;                                                                  \
  }