#pragma once
#include <Engine/Logger.hpp>

namespace Engine {
extern void Init();

} // namespace Engine

int main(int argc, char **argv) {
  Engine::Logger::Init();
  Engine::Init();
  return 0;
}