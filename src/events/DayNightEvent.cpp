#include "DayNightEvent.hpp"

#include <iostream>

DayNightEvent::DayNightEvent() : Event {ActionType::DAY_NIGNT, "DAYNIGHT"} {}

DayNightEvent::DayNightEvent(Mode _mode)
    : Event {ActionType::DAY_NIGNT, "DAYNIGHT"}
    , mode {_mode} {}

void DayNightEvent::Execute() {
  std::cout << name << ": ";
  if (mode == Mode::NIGHT) {
    // TODO: Night mode.
    std::cout << "NIGHT MODE IS ON\n";
  } else if (mode == Mode::DAY) {
    // TODO: Day mode.
    std::cout << "DAY MODE IS ON\n";
  }
}

void DayNightEvent::SetMode(Mode _mode) { mode = _mode; }

DayNightEvent::Mode DayNightEvent::GetMode() const { return mode; }
