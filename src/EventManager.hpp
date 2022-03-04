#pragma once
#include <unordered_map>

#include "Event.hpp"

class EventManager {
public:
	void Push();
private:
  std::unordered_map<EventType, Event> events;
};