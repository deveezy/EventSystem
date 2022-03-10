#pragma once

#include "../common/Datatypes.hpp"

class Task {
public:
  Task() noexcept = default;
  Task(int32_t _bounded_id, SchedType _sched_type, uint64_t _time_begin = 0, uint64_t _time_end = 0);
  Task(const Task &) noexcept = default;
  Task(Task &&) noexcept      = default;
  Task &operator=(const Task &) noexcept = default;
  Task &operator=(Task &&) noexcept = default;
  virtual ~Task()                   = default;

public:
  int32_t GetBoundedId() const;
  void SetBoundedId(int32_t _bounded_id);
  SchedType GetShedType() const;
  void SetSchedType(SchedType _sched_type);
  uint64_t GetTimeBegin() const;
  void SetTimeBegin(uint64_t _time_begin);
  uint64_t GetTimeEnd() const;
  void SetTimeEnd(uint64_t _time_end);

private:
  int32_t bounded_id {-1};
  SchedType sched_type {};
  uint64_t time_begin {0};
  uint64_t time_end {0};
};