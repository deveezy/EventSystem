#include "EventManager.hpp"

#include <iostream>


EventManager::EventManager() : events {20} {
  handler = std::async(&EventManager::processEvents, this);
  // TODO: use SmartThread
}

EventManager::~EventManager() = default;

void EventManager::Push(EventType _event_type) { events.TryPush(_event_type); }

void EventManager::Bind(EventType _event_type, std::unique_ptr<Event> &&_event) {
  event_actions.emplace(_event_type, std::move(_event));
}

void EventManager::Unbind(EventType _event_type) {
  
}

void EventManager::processEvents() {
  EventType event_type;
  std::cout << "Wait for event...\n";
  std::cout.flush();
  events.WaitAndPop(event_type);  // blocked
  std::cout << "The queue has been filled\n";

  for (const auto &element : event_actions) {
    if (element.first & event_type) { element.second->Execute(); }
  }
}

void EventManager::initEvents() {
  // Get values from DB and push to event_actions map.
}
