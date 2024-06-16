#pragma once
#include <memory>

namespace Platform {
class Window;
}

namespace Engine {

struct WindowProps {
  unsigned int width;
  unsigned int height;
  const char *title;
};

struct Window {
  static std::shared_ptr<Platform::Window> Create();
};

} // namespace Engine
