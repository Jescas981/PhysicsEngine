#include <Renderer/Program.hpp>
#include <glad/glad.h>

namespace Renderer {
Program::Program() { id_ = glCreateProgram(); }

void Program::Link() const { glLinkProgram(id_); }

void Program::Bind() const { glUseProgram(id_); }

void Program::Unbind() const { glUseProgram(0); }
} // namespace Renderer