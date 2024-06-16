#pragma once

namespace Renderer {
class VertexBuffer {
public:
  VertexBuffer();
  void Bind();
  void Unbind();

private:
  unsigned int id;
};
} // namespace Renderer