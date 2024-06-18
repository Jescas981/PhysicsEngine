#pragma once
#include <string>

namespace IO {
namespace Procedures {
class PlainText {
public:
  using ResultType = std::string;
  using InputType = std::string;

  static ResultType Read(const std::string &filepath);
};

} // namespace Procedures
} // namespace IO