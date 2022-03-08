#include <stdint.h>

#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <thread>
#include <utility>

#include "EventManager.hpp"
#include "events/DayNightEvent.hpp"
#include "events/ResponseEvent.hpp"

int main() {
#if 1
  EventManager em;
  std::unique_ptr<Event> response_event {new ResponseEvent};
  std::unique_ptr<Event> day_night_event {new DayNightEvent};
  em.Bind(EventType::MOTION | EventType::TEMPERATURE, std::move(response_event));
  // em.Bind(EventType::TEMPERATURE, std::move(day_night_event));
  std::this_thread::sleep_for(std::chrono::seconds(2));
  em.Push(EventType::TEMPERATURE);
  std::this_thread::sleep_for(std::chrono::seconds(2));
  em.Exclude(3, EventType::TEMPERATURE);
  em.Exclude(3, EventType::MOTION);
  em.Push(EventType::TEMPERATURE);
#endif

  // uint64_t db_idx = 1ull << (4 * 8);
  // uint64_t val = 18446744073709551615u;
  return 0;
}