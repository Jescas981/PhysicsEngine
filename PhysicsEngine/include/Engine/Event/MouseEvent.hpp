#pragma once
#include <Engine/Event/Event.hpp>
#include <sstream>

namespace Engine {
class MousePressedEvent : public Event {
public:
  MousePressedEvent(int button) : button_(button) {}
  EventDoc(MousePressedEvent);

  inline int GetButton() const { return button_; }

  std::string GetStatus() override {
    std::ostringstream oss;
    oss << "MouseEvent: Button " << button_ << " pressed";
    return oss.str();
  }

private:
  int button_;
};

class MouseReleasedEvent : public Event {
public:
  MouseReleasedEvent(int button) : button_(button) {}
  EventDoc(MouseReleasedEvent);

  inline int GetButton() const { return button_; }

  std::string GetStatus() override {
    std::ostringstream oss;
    oss << "MouseEvent: Button " << button_ << " released";
    return oss.str();
  }

private:
  int button_;
};

class MousePositionEvent : public Event {
public:
  MousePositionEvent(double xpos, double ypos) : xpos_(xpos), ypos_(ypos) {}
  EventDoc(MouseScrollEvent);

  inline double GetXPosition() const { return xpos_; }

  inline double GetYPosition() const { return ypos_; }

  std::string GetStatus() override {
    std::ostringstream oss;
    oss << "MouseEvent: Position x: " << xpos_ << " y: " << ypos_;
    return oss.str();
  }

private:
  double xpos_;
  double ypos_;
};

class MouseScrollEvent : public Event {
public:
  MouseScrollEvent(double xoffset, double yoffset)
      : xoffset_(xoffset), yoffset_(yoffset) {}
  EventDoc(MouseScrollEvent);

  inline double GetXOffset() const { return xoffset_; }

  inline double GetYOffset() const { return yoffset_; }

  std::string GetStatus() override {
    std::ostringstream oss;
    oss << "MouseEvent: Scroll x: " << xoffset_ << " y: " << yoffset_;
    return oss.str();
  }

private:
  double xoffset_;
  double yoffset_;
};
} // namespace Engine