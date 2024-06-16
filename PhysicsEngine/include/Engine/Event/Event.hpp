#pragma once
#include <string>

#define EventDoc(name)                                                         \
  virtual const char *GetName() override { return #name; }                     \
  static const char *GetEventName() { return #name; }

namespace Engine {
class Event {
public:
  virtual const char *GetName() { return "Event"; };
  virtual std::string GetStatus() = 0;
};
} // namespace Engine