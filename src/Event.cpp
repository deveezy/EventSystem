#include "Event.hpp"

Event::Event(ActionType _type) : name {}, action_type {_type} {}

Event::Event(ActionType _type, std::string _name) : name {std::move(_name)}, action_type {_type} {}

void Event::SetName(std::string _name) { name = std::move(_name); }

std::string Event::GetName() const { return name; }

void Event::SetType(ActionType _type) { action_type = _type; }

ActionType Event::GetType() const { return action_type; }
