#include "DayNightTask.hpp"

#include <iostream>

DayNightTask::DayNightTask(Mode _begin, Mode _end)
    : Task {Trigger::DAYNIGHT}
    , begin {_begin}
    , end {_end} {}

void DayNightTask::OnBegin() {
  // TODO: set begin mode to the day_night system from engine.
  std::cout << "BEGIN MODE WAS SET\n";
}

void DayNightTask::OnEnd() {
  // TODO: set end mode to the day_night system from engine.
  std::cout << "END MODE WAS SET\n";
  std::cout << "";
}
