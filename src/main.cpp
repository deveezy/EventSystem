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

#include "EventManager.hpp"
#include "events/DayNightEvent.hpp"
#include "events/Event.hpp"
#include "events/ResponseEvent.hpp"

int main() {
  EventManager em;
#if 0
  std::shared_ptr<Event> response_event {new ResponseEvent};
  std::shared_ptr<Event> day_night_event {new DayNightEvent(DayNightEvent::Mode::DAY)};
  em.Bind(Trigger::MOTION, response_event);
  // em.Bind(Trigger::TEMPERATURE, day_night_event);
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::this_thread::sleep_for(std::chrono::seconds(2));
  em.Exclude(3, Trigger::MOTION);
#endif
}