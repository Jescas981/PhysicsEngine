#include <Engine/Logger.hpp>
#include <memory>
#include <spdlog/logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace Engine {

std::unique_ptr<Logger> Logger::logger_;

struct LoggerImpl {
  std::shared_ptr<spdlog::logger> logger;
};

Logger &Logger::GetInstance() {
  if (logger_ == nullptr) {
    logger_ = std::unique_ptr<Logger>(new Logger());
    logger_->logger_impl_ = std::make_shared<LoggerImpl>();
    spdlog::set_pattern("%^[%T] %n: %v%$");
    spdlog::set_level(spdlog::level::trace);
    logger_->logger_impl_->logger = spdlog::stdout_color_mt("Core");
  }
  return *logger_;
}

void Logger::Info(const std::string &msg) const {
  logger_impl_->logger->trace(msg);
}
void Logger::Warn(const std::string &msg) const {
  logger_impl_->logger->warn(msg);
}
void Logger::Trace(const std::string &msg) const {
  logger_impl_->logger->trace(msg);
}
void Logger::Critical(const std::string &msg) const {
  logger_impl_->logger->critical(msg);
}

void Logger::Info(const char *msg) const { logger_impl_->logger->trace(msg); }
void Logger::Warn(const char *msg) const { logger_impl_->logger->warn(msg); }
void Logger::Trace(const char *msg) const { logger_impl_->logger->trace(msg); }
void Logger::Critical(const char *msg) const {
  logger_impl_->logger->critical(msg);
}

} // namespace Engine