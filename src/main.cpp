#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <thread>

#include "EventManager.hpp"
#include "events/DayNightEvent.hpp"
#include "events/ResponseEvent.hpp"


int main() {
  EventManager em;
  std::unique_ptr<Event> response_event {new ResponseEvent};
  std::unique_ptr<Event> day_night_event {new DayNightEvent};
  em.Bind(EventType::RESPONSE, std::move(response_event));
  em.Bind(EventType::TYPE_TWO, std::move(day_night_event));
  std::this_thread::sleep_for(std::chrono::seconds(5));
  std::cout << "after sleep\n";
  std::cout.flush();
  em.Push(EventType::TYPE_TWO);
  return 0;
}