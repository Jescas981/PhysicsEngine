#include "Renderer/Program.hpp"
#include <Engine/Application.hpp>
#include <Engine/Logger.hpp>
#include <IO/File.hpp>
#include <IO/Procedures/PlainText.hpp>
#include <Math/Vector.hpp>
#include <Renderer/Shader.hpp>
#include <Renderer/VertexArray.hpp>
#include <Renderer/VertexBuffer.hpp>
#include <glad/glad.h>
//
#include <GLFW/glfw3.h>

#include <vector>

class App : public Engine::Application {
public:
  void Init() override {
    std::vector<Math::Vector3f> triangle{{-0.5f, -0.5f, 0.0f}, //
                                         {0.5f, -0.5f, 0.0f},  //
                                         {0.0f, 0.5f, 0.0f}};

    IO::FileRead<IO::Procedures::PlainText> file_frag{
        "/home/jescas/Desktop/PhysicsEngine/App/Shaders/FragmentShader.glsl"};

    IO::FileRead<IO::Procedures::PlainText> file_vert{
        "/home/jescas/Desktop/PhysicsEngine/App/Shaders/VertexShader.glsl"};

    Renderer::Shader shader_frag{file_frag, Renderer::Shader::FragmentShader};
    Renderer::Shader vert_frag{file_vert, Renderer::Shader::VertexShader};

    shader_frag.Compile();
    vert_frag.Compile();

    shader_frag.Attach(program_);
    vert_frag.Attach(program_);
    program_.Link();

    vao = std::make_unique<Renderer::VertexArray>();
    vbo = std::make_unique<Renderer::VertexBuffer>(triangle);
  }

  void Update() override {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    program_.Bind();
    vao->Bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
  }

private:
  std::unique_ptr<Renderer::VertexBuffer> vbo;
  std::unique_ptr<Renderer::VertexArray> vao;
  Renderer::Program program_;
};

APPLICATION(App)