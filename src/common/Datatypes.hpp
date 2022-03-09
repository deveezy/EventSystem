#pragma once
#include "Flags.hpp"

enum class TriggerType {
  DAYNIGHT = 1 << 0,
  MOTION   = 1 << 1,
};

enum class ActionType { RESPONSE = 1, DAY_NIGNT, IR, COUNT };

enum class SchedType { ALWAYS = 1, WEEKLY, DAILY, WEEKDAYS, WEEKENDS, COUNT };

ENUM_FLAGS(TriggerType)
ENUM_FLAGS(ActionType)
ENUM_FLAGS(SchedType)