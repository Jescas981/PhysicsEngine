#include <Renderer/VertexBuffer.hpp>
#include <glad/glad.h>

namespace Renderer {
VertexBuffer::VertexBuffer(std::vector<Math::Vector3f> vertices) {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ARRAY_BUFFER, id);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Math::Vector3f),
               vertices.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
}

void VertexBuffer::Bind() { glBindBuffer(GL_ARRAY_BUFFER, id); }

void VertexBuffer::Unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
} // namespace Renderer