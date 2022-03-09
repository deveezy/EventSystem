#pragma once
#include "Task.hpp"

class DayNightTask : public Task {
public:
  enum class Mode { DAY = 1, NIGHT };

public:
  DayNightTask(Mode _begin, Mode _end);
  DayNightTask(const DayNightTask &) noexcept = default;
  DayNightTask(DayNightTask &&) noexcept      = default;
  DayNightTask &operator=(const DayNightTask &) noexcept = default;
  DayNightTask &operator=(DayNightTask &&) noexcept = default;

public:
  void OnBegin() override;
  void OnEnd() override;

private:
	Mode begin;
	Mode end;
};

ENUM_FLAGS(DayNightTask::Mode);