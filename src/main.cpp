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


int main() {
  EventManager em;
#if 1
  std::shared_ptr<Event> response_event {new ResponseEvent};
  std::shared_ptr<Event> day_night_event {new DayNightEvent(DayNightEvent::Mode::DAY)};
  em.Bind(EventType::MOTION, response_event);
  // em.Bind(EventType::TEMPERATURE, day_night_event);
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::this_thread::sleep_for(std::chrono::seconds(2));
  em.Exclude(3, EventType::MOTION);
#endif
}