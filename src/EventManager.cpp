#include "EventManager.hpp"

#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <utility>

#include "events/DayNightEvent.hpp"

// TODO: fake DB.
static uint32_t id_counter = 3;

EventManager::EventManager() : events {20} {
  handler = std::async(&EventManager::processEvents, this);
  // TODO: use SmartThread
}

EventManager::~EventManager() = default;

void EventManager::Push(Flags<EventType> _event_type) { events.TryPush(_event_type); }

void EventManager::Bind(Flags<EventType> _event_type, std::unique_ptr<Event> &&_event) {
  _event->SetEventType(_event_type);
  event_actions.emplace(id_counter, std::move(_event));
  ++id_counter;
}

void EventManager::Exclude(uint32_t _id, Flags<EventType> _event_type) {
  for (auto it = event_actions.cbegin(); it != event_actions.cend();) {
    if (it->first == _id) {
      auto existed = it->second->GetEventType();
      existed &= (~_event_type);
      if (!existed) {
        event_actions.erase(it++);
      } else {
        it->second->SetEventType(existed);
        ++it;
      }
    } else {
      ++it;
    }
  }
}

void EventManager::processEvents() {
  while (true) {
    EventType event_type;
    std::cout << "Wait for event...\n";
    events.WaitAndPop(event_type);  // block
    std::cout << "New event just arrived\n";

    for (const auto &it : event_actions) {
      if (it.second->GetEventType() & event_type) it.second->Execute();
    }
  }
}

void EventManager::initEvents() {
  // TODO: Get values from DB and push to event_actions map.
}
