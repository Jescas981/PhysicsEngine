#include <Renderer/VertexArray.hpp>
#include <glad/glad.h>

namespace Renderer {

VertexArray::VertexArray() {
  glGenVertexArrays(1, &id);
  glBindVertexArray(id);
}

void VertexArray::Bind() { glBindVertexArray(id); }

void VertexArray::Unbind() { glBindVertexArray(0); }
} // namespace Renderer