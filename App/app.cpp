#include <Engine/Application.hpp>
#include <Engine/Logger.hpp>
#include <Math/Vector.hpp>
#include <Renderer/Shader.hpp>
#include <Renderer/VertexArray.hpp>
#include <Renderer/VertexBuffer.hpp>
#include <Utils/IO/File.hpp>
#include <vector>

void Engine::Init() {
  std::vector<Math::Vector3f> triangle{{-0.5f, -0.5f, 0.0f}, //
                                       {0.5f, -0.5f, 0.0f},  //
                                       {0.0f, 0.5f, 0.0f}};

  std::vector<unsigned int> indices{0, 1, 2};

  Utils::File file{
      "/home/jescas/Desktop/PhysicsEngine/App/Shaders/FragmentShader.glsl"};
      
  Renderer::Shader shader{file};


  Renderer::VertexBuffer vbo;
  Renderer::VertexArray vao{triangle};
}

void Engine::Update() {}

void Engine::OnEvent(Event &e) { CORE_TRACE(e.GetStatus()); }