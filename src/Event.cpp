#include "Event.hpp"

Event &Event::operator=(EventType _type) {
  type = _type;
  return *this;
}

void Event::SetName(std::string _name) { name = std::move(_name); }

std::string Event::GetName() const { return name; }
