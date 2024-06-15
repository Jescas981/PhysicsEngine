#include <Engine/Logger.hpp>
#include <Platform/Window/WindowLinux.hpp>
#include <glad/glad.h>
//
#include <GLFW/glfw3.h>

namespace Platform {
void WindowLinux::Init(const Engine::WindowProps &props) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(props.width, props.height, props.title,
                                        nullptr, nullptr);

  if (window == nullptr) {
    CORE_ERROR("Failed to create Window in Linux");
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    CORE_ERROR("Failed to load GLAD");
  }
  
}
}; // namespace Platform