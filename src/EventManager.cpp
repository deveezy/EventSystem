#include "EventManager.hpp"

EventManager::EventManager() { handler = std::async(&EventManager::processEvents, this); }

EventManager::~EventManager() = default;

void EventManager::Push(EventType _event_type) {
  // mtx lock
  events.push(_event_type);
  // notify
}

void EventManager::Bind(EventType _event_type, std::unique_ptr<Event> _event) {}

void EventManager::processEvents() {}
