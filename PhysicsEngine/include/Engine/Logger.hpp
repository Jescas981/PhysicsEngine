#pragma once
#include <memory>

namespace Engine {

class LoggerImpl;

class Logger {
private:
  Logger() {}

public:
  static Logger &GetInstance();

  void Info(const std::string &msg) const;
  void Warn(const std::string &msg) const;
  void Trace(const std::string &msg) const;
  void Critical(const std::string &msg) const;

  void Info(const char *msg) const;
  void Warn(const char *msg) const;
  void Trace(const char *msg) const;
  void Critical(const char *msg) const;

private:
  std::shared_ptr<LoggerImpl> logger_impl_;
  static std::unique_ptr<Logger> logger_;
};
} // namespace Engine

#define CORE_INFO(msg) Engine::Logger::GetInstance().Info(msg);
#define CORE_WARN(msg) Engine::Logger::GetInstance().Warn(msg);
#define CORE_TRACE(msg) Engine::Logger::GetInstance().Trace(msg);
#define CORE_ERROR(msg) Engine::Logger::GetInstance().Critical(msg);
