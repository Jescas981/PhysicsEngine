#include "Engine/Logger.hpp"
#include <Renderer/Shader.hpp>
#include <glad/glad.h>

namespace Renderer {
Shader::Shader(IO::FileRead<IO::Procedures::PlainText> &file, ShaderType type) {
  std::string content = file.Read();

  switch (type) {
  case FragmentShader:
    id_ = glCreateShader(GL_FRAGMENT_SHADER);
    break;
  case VertexShader:
    id_ = glCreateShader(GL_VERTEX_SHADER);
    break;
  }
  const char *source = static_cast<const char *>(content.c_str());
  glShaderSource(id_, 1, &source, nullptr);
}

bool Shader::Compile() {
  glCompileShader(id_);
  int success;

  glGetShaderiv(id_, GL_COMPILE_STATUS, &success);

  if (!success) {
    int buffer_length;
    glGetShaderiv(id_, GL_INFO_LOG_LENGTH, &buffer_length);

    char *buffer = new char[buffer_length];
    glGetShaderInfoLog(id_, buffer_length, nullptr, buffer);
    CORE_ERROR(buffer);
    delete[] buffer;
  }

  return success;
}

void Shader::Attach(const Renderer::Program &program) {
  glAttachShader(program.GetId(), id_);
}

Shader::~Shader() { glDeleteShader(id_); }

} // namespace Renderer