#include <Engine/Window.hpp>
#include <Platform/Window/WindowLinux.hpp>

namespace Engine {
std::shared_ptr<Platform::Window> Window::Create() {
  return std::make_shared<Platform::WindowLinux>();
}

} // namespace Engine