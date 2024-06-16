#include <Engine/Event/Event.hpp>
#include <Engine/Event/MouseEvent.hpp>
#include <Engine/Logger.hpp>
#include <functional>
#include <glad/glad.h>
//
#include <GLFW/glfw3.h>
#include <Platform/Window/WindowLinux.hpp>

namespace Platform {

class RawWindow {
public:
  RawWindow(unsigned int width, unsigned int height, const char *title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window_ = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (window_ == nullptr) {
      CORE_ERROR("Failed to create Window in Linux");
    }

    glfwMakeContextCurrent(window_);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      CORE_ERROR("Failed to load GLAD");
    }
  }

  void SetupListeners(std::function<void(Engine::Event &)> listener) {

    listener_ = listener;

    glfwSetWindowUserPointer(window_, reinterpret_cast<void *>(this));

    glfwSetScrollCallback(
        window_, [](GLFWwindow *window, double xoffset, double yoffset) {
          RawWindow *raw =
              reinterpret_cast<RawWindow *>(glfwGetWindowUserPointer(window));
          Engine::MousePositionEvent event{xoffset, yoffset};
          raw->listener_(event);
        });

    glfwSetCursorPosCallback(
        window_, [](GLFWwindow *window, double xpos, double ypos) {
          RawWindow *raw =
              reinterpret_cast<RawWindow *>(glfwGetWindowUserPointer(window));
          Engine::MousePositionEvent event{xpos, ypos};
          raw->listener_(event);
        });

    glfwSetMouseButtonCallback(
        window_, [](GLFWwindow *window, int button, int action, int mods) {
          RawWindow *raw =
              reinterpret_cast<RawWindow *>(glfwGetWindowUserPointer(window));

          switch (action) {
          case GLFW_PRESS: {
            Engine::MousePressedEvent event{button};
            raw->listener_(event);
            break;
          }
          case GLFW_RELEASE: {
            Engine::MouseReleasedEvent event{button};
            raw->listener_(event);
            break;
          }
          }
        });
  }

  ~RawWindow() {
    glfwDestroyWindow(window_);
    glfwTerminate();
  }

  GLFWwindow *GetWindow() { return window_; }

private:
  GLFWwindow *window_;
  std::function<void(Engine::Event &)> listener_;
};

void WindowLinux::Init(const Engine::WindowProps &props) {
  CORE_TRACE("Initializing window");
  raw_ = std::make_unique<RawWindow>(props.width, props.height, props.title);
}

void WindowLinux::SetEventListener(
    std::function<void(Engine::Event &)> listener) {
  raw_->SetupListeners(listener);
}

bool WindowLinux::Running() const {
  glfwPollEvents();
  return !glfwWindowShouldClose(raw_->GetWindow());
}
}; // namespace Platform