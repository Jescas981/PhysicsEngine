#pragma once
namespace Renderer {

class Program {
public:
  Program();

  inline unsigned int GetId() const { return id_; }

  void Link() const;

  void Bind() const;

  void Unbind() const;

private:
  unsigned int id_;
};
} // namespace Renderer