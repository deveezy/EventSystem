#include "Task.hpp"

Task::Task(TriggerType _trigger_type) : trigger_type {_trigger_type} {}

void Task::SetTriggerType(Flags<TriggerType> _trigger_type) noexcept {
  trigger_type = _trigger_type;
}

Flags<TriggerType> Task::GetTriggerType() const noexcept { return trigger_type; }
