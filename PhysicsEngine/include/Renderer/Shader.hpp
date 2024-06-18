#pragma once
#include <IO/File.hpp>
#include <IO/Procedures/PlainText.hpp>
#include <Renderer/Program.hpp>

namespace Renderer {
class Shader {

public:
  enum ShaderType { FragmentShader, VertexShader };

  Shader(IO::FileRead<IO::Procedures::PlainText> &file, ShaderType type);

  bool Compile();

  void Attach(const Renderer::Program &program);

  ~Shader();

private:
  unsigned int id_;
};
} // namespace Renderer