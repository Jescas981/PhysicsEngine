#include <Renderer/VertexArray.hpp>
#include <glad/glad.h>

namespace Renderer {

VertexArray::VertexArray(std::vector<Math::Vector3f> vertices) {
  glGenVertexArrays(1, &id);
  glBindVertexArray(id);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
               vertices.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
}

void VertexArray::Bind() { glBindVertexArray(id); }

void VertexArray::Unbind() { glBindVertexArray(0); }
} // namespace Renderer