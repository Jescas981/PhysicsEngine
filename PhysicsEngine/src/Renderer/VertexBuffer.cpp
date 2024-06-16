#include <Renderer/VertexBuffer.hpp>
#include <glad/glad.h>

namespace Renderer {
VertexBuffer::VertexBuffer() {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ARRAY_BUFFER, id);
  
}

void VertexBuffer::Bind() { glBindBuffer(GL_ARRAY_BUFFER, id); }

void VertexBuffer::Unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
} // namespace Renderer