#include <stdint.h>

#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <thread>
#include <type_traits>
#include <utility>

#include "Event.hpp"
#include "EventManager.hpp"
#include "events/DayNightEvent.hpp"
#include "events/ResponseEvent.hpp"

using ActionDayNight = std::integral_constant<ActionType, ActionType::DAY_NIGNT>;
using ActionResponse = std::integral_constant<ActionType, ActionType::RESPONSE>;

template <typename... Args>
std::shared_ptr<Event> GetEvent(ActionDayNight, Args &&..._args) {
  std::shared_ptr<Event> event;
  event = std::shared_ptr<DayNightEvent>(new DayNightEvent(std::forward<Args...>(_args...)));
  return event;
}

template <typename... Args>
std::shared_ptr<Event> GetEvent(ActionResponse, Args &&..._args) {
  std::shared_ptr<Event> event;
  event = std::shared_ptr<ResponseEvent>(new ResponseEvent(std::forward<Args...>(_args...)));
  return event;
}

int main() {
  EventManager em;
#if 0
  std::shared_ptr<Event> response_event {new ResponseEvent};
  std::shared_ptr<Event> day_night_event {new DayNightEvent(DayNightEvent::Mode::DAY)};
  em.Bind(EventType::MOTION | EventType::TEMPERATURE, response_event);
  // em.Bind(EventType::TEMPERATURE, day_night_event);
  std::this_thread::sleep_for(std::chrono::seconds(2));
  em.Push(EventType::TEMPERATURE);
  std::this_thread::sleep_for(std::chrono::seconds(2));
  em.Exclude(3, EventType::TEMPERATURE);
  em.Exclude(3, EventType::MOTION);
  em.Push(EventType::TEMPERATURE);
#endif

  // em.CreateEvent(1, DayNightEvent::Mode::DAY);
  // em.CreateEvent(ActionType::RESPONSE, 10);

  // int a = 10;
  // int b = 20;
  // int c = 30;

  const auto type = ActionType::DAY_NIGNT;
  if (type == ActionType::DAY_NIGNT) {
    auto ret = GetEvent(ActionDayNight {}, DayNightEvent::Mode::NIGHT);
  } else if (type == ActionType::RESPONSE) {
    auto ret = GetEvent(ActionResponse {}, 10);
  }
}