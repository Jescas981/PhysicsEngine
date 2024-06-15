#include <Engine/Logger.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Engine {

std::shared_ptr<spdlog::logger> Logger::logger_;

void Logger::Init() {
  spdlog::set_pattern("%^[%T] %n: %v%$");
  logger_ = spdlog::stdout_color_mt("Core");
}

} // namespace Engine