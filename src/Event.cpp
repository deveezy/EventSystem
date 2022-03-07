#include "Event.hpp"

Event::Event(EventType _type) : name {}, type {_type} {}

Event::Event(EventType _type, std::string _name) : name {std::move(_name)}, type {_type} {}

Event &Event::operator=(EventType _type) {
  type = _type;
  return *this;
}

void Event::SetName(std::string _name) { name = std::move(_name); }

std::string Event::GetName() const { return name; }

void Event::SetType(EventType _type) { type = _type; }

EventType Event::GetType() const { return type; }
