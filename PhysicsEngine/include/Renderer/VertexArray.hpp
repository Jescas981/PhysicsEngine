#pragma once
#include <Math/Vector.hpp>
#include <vector>

namespace Renderer {
class VertexArray {
public:
  VertexArray(std::vector<Math::Vector3f> vertices);
  void Bind();
  void Unbind();

private:
  unsigned int id;
};
} // namespace Renderer