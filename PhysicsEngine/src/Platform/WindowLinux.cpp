#include <Engine/Event/Event.hpp>
#include <Engine/Logger.hpp>
#include <functional>
#include <glad/glad.h>
//
#include <GLFW/glfw3.h>
#include <Platform/Window/WindowLinux.hpp>

namespace Platform {

struct RawWindowProps {
  unsigned width;
  unsigned height;
  const char *title;
  std::function<void(Engine::Event &event)> listener;
};

class RawWindow {
public:
  RawWindow(const RawWindowProps& props) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window_ = glfwCreateWindow(props.width, props.height, props.title, nullptr,
                               nullptr);

    if (window_ == nullptr) {
      CORE_ERROR("Failed to create Window in Linux");
    }

    glfwMakeContextCurrent(window_);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      CORE_ERROR("Failed to load GLAD");
    }

    glfwSetWindowUserPointer(window_, &props);
  }

  void SetupListeners() {
    glfwSetMouseButtonCallback(
        window_, [](GLFWwindow *window, int button, int action, int mods) {

        });
  }

  ~RawWindow() {
    glfwDestroyWindow(window_);
    glfwTerminate();
  }

  GLFWwindow *GetWindow() { return window_; }

private:
  GLFWwindow *window_;
  RawWindowProps props_;
};

void WindowLinux::Init(const Engine::WindowProps &props) {
  CORE_TRACE("Initializing window");
  raw_ = std::make_unique<RawWindow>(RawWindowProps{400, 400, "da", listener_});
  raw_->SetupListeners();
}

bool WindowLinux::Running() const {
  return !glfwWindowShouldClose(raw_->GetWindow());
}
}; // namespace Platform