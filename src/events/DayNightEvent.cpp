#include "DayNightEvent.hpp"

#include <iostream>

DayNightEvent::DayNightEvent() : Event {ActionType::DAY_NIGNT, "DAYNIGHT"} {}

void DayNightEvent::Execute() { std::cout << name << "\n"; }
