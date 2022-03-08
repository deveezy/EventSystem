#include "Event.hpp"

Event::Event(ActionType _action_type, EventType _event_type)
    : name {}
    , action_type {_action_type}
    , event_type {_event_type} {}

Event::Event(ActionType _type, std::string _name) : name {std::move(_name)}, action_type {_type} {}

void Event::SetName(std::string _name) { name = std::move(_name); }

std::string Event::GetName() const { return name; }

void Event::SetActionType(ActionType _type) { action_type = _type; }

Flags<ActionType> Event::GetActionType() const { return action_type; }

void Event::SetEventType(EventType _event_type) { event_type = _event_type; }

Flags<EventType> Event::GetEventType() const { return event_type; }
