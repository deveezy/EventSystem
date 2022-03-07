#include "EventManager.hpp"

EventManager::EventManager() : events {20} {
  handler = std::async(&EventManager::processEvents, this);
  // TODO: use SmartThread
}

EventManager::~EventManager() = default;

void EventManager::Push(EventType _event_type) { events.TryPush(_event_type); }

void EventManager::Bind(EventType _event_type, std::unique_ptr<Event> _event) {}

void EventManager::processEvents() {
  EventType event_type;
  events.WaitAndPop(event_type);  // blocked

  for (const auto &element : event_actions) {
    if (element.first & event_type) { element.second->Execute(); }
  }
}
