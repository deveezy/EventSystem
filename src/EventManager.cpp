#include "EventManager.hpp"

#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>

#include "events/Event.hpp"

// TODO: fake DB.
static uint32_t id_counter = 3;

EventManager::EventManager() : events {20} {
  handler = std::async(&EventManager::processEvents, this);
  // TODO: use SmartThread
}

EventManager::~EventManager() = default;

void EventManager::CreateActionDay(std::string _name, bool _ir, bool _wb) {
  // TODO: save to DayReactions table
}

void EventManager::CreateActionNight(std::string _name, bool _ir, bool _wb) {
  // TODO: save to NightReactions table
}

void EventManager::Bind(Trigger _trigger, Action _action, int32_t _action_id) {
  // TODO: save to bounded table in DB (join).
}

void EventManager::Unbind(int32_t _id) {
  // TODO: remove from DB and from map if exists.
}

void EventManager::Exclude(int32_t _id, Trigger _trigger) {
  // TODO: Exclude/delete _trigger from FindTriggerById(_id).
}

void EventManager::EnableTrigger(int32_t _id, bool _enable) {
  // TODO: push to event_actions and write active to DB (table bounded).
  // TODO: scheduler.Push Task. Формируем Task с помощью, которые тащим из БД (shit happens).
  // scheduler.Push(trigger, task);
}

void EventManager::Schedule(int32_t _id, SchedType _sched_type, uint64_t _begin, uint64_t _end) {
  // TODO: Save to DB.
}

void EventManager::Push(Trigger _trigger) {
  // TODO: вызвать метод из scheduler, который будет проверять,
  // есть ли сейчас в планах такой триггер.
  const auto bounded_id = scheduler.Acquire(_trigger);
  if (bounded_id < 0) {
    /// INFO: event not scheduled.
    return;
  }
  events.TryPush(bounded_id);
}

void EventManager::processEvents() {
  while (true) { // while (_is_running)
    int32_t bounded_id;
    std::cout << "Wait for event...\n";
    events.WaitAndPop(bounded_id);  // block
    std::cout << "New event just arrived\n";
    event_actions[bounded_id]->Execute();
  }
}
