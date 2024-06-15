#pragma once
#include <memory>
#include <spdlog/spdlog.h>

namespace Engine {
class Logger {
public:
  static void Init();
  static std::shared_ptr<spdlog::logger> GetLogger() { return logger_; }

private:
  static std::shared_ptr<spdlog::logger> logger_;
};
} // namespace Engine