#pragma once


namespace Renderer {
class VertexArray {
public:
  VertexArray();
  void Bind();
  void Unbind();

private:
  unsigned int id;
};
} // namespace Renderer