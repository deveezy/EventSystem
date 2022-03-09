#pragma once

#include "../common/Datatypes.hpp"

class Task {
public:
  Task() noexcept = default;
  Task(TriggerType _trigger_type);
  Task(const Task &) noexcept = default;
  Task(Task &&) noexcept      = default;
  Task &operator=(const Task &) noexcept = default;
  Task &operator=(Task &&) noexcept = default;
  virtual ~Task()                   = default;

public:
  virtual void OnBegin() = 0;
  virtual void OnEnd()   = 0;

public:
  void SetTriggerType(Flags<TriggerType> _trigger_type) noexcept;
  Flags<TriggerType> GetTriggerType() const noexcept;

private:
  Flags<TriggerType> trigger_type {};
  Flags<SchedType> sched_type {};
};