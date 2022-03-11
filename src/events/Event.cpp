#include "Event.hpp"

Event::Event(Action _action, Trigger _event_type)
    : name {}
    , action_type {_action}
    , event_type {_event_type} {}

Event::Event(Action _type, std::string _name) : name {std::move(_name)}, action_type {_type} {}

void Event::SetName(std::string _name) { name = std::move(_name); }

std::string Event::GetName() const { return name; }

void Event::SetActionType(Action _type) { action_type = _type; }

Flags<Action> Event::GetActionType() const { return action_type; }