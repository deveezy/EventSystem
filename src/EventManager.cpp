#include "EventManager.hpp"

#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>

#include "events/Event.hpp"
#include "events/DayNightEvent.hpp"
#include "events/ResponseEvent.hpp"

// TODO: fake DB.
static uint32_t id_counter = 3;

EventManager::EventManager() : events {20} {
  handler = std::async(&EventManager::processEvents, this);
  // TODO: use SmartThread
}

EventManager::~EventManager() = default;

void EventManager::Push(Flags<TriggerType> _event_type) { events.TryPush(_event_type); }

std::shared_ptr<Event> EventManager::CreateEvent(ActionType _action_type) {
  std::shared_ptr<Event> event = nullptr;
  switch (_action_type) {
    case ActionType::DAY_NIGNT: event = std::make_shared<DayNightEvent>(); break;
    case ActionType::RESPONSE: event = std::make_shared<ResponseEvent>(); break;
    // TODO: add other types
    default: break;
  }
  return event;
}

void EventManager::Bind(Flags<TriggerType> _event_type, std::shared_ptr<Event> _event) {
  _event->SetTriggerType(_event_type);
  event_actions.emplace(id_counter, _event);
  ++id_counter;
}

void EventManager::Unbind(uint32_t _id, Flags<TriggerType> _event_type) { event_actions.erase(_id); }

void EventManager::Exclude(uint32_t _id, Flags<TriggerType> _event_type) {
  for (auto it = event_actions.begin(); it != event_actions.end();) {
    if (it->first == _id) {
      auto existed = it->second->GetTriggerType();
      existed &= (~_event_type);
      if (!existed) {
        it = event_actions.erase(it);
        continue;
      } else {
        it->second->SetTriggerType(existed);
      }
    }
    ++it;
  }
}

void EventManager::processEvents() {
  while (true) {
    TriggerType event_type;
    std::cout << "Wait for event...\n";
    events.WaitAndPop(event_type);  // block
    std::cout << "New event just arrived\n";

    for (const auto &it : event_actions) {
      if (it.second->GetTriggerType() & event_type) it.second->Execute();
    }
  }
}

void EventManager::initEvents() {
  // TODO: Get values from DB and push to event_actions map.
}
