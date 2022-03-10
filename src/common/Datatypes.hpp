#pragma once
#include "Flags.hpp"

enum class Trigger {
  NONE   = 0,
  DAY    = 1 << 0,
  NIGHT  = 1 << 1,
  MOTION = 1 << 2,
};

enum class Action { RESPONSE = 1, DAY, NIGHT, IR, COUNT };

enum class SchedType { ALWAYS = 1, WEEKLY, DAILY, WEEKDAYS, WEEKENDS, COUNT };

ENUM_FLAGS(Trigger)
ENUM_FLAGS(Action)
ENUM_FLAGS(SchedType)