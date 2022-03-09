#pragma once

#include <ctime>
#include <memory>

#include "Event.hpp"

class Task {
  
};

class TaskScheduler {
public:
  TaskScheduler();
  ~TaskScheduler();
  TaskScheduler(const TaskScheduler &) noexcept = delete;
  TaskScheduler(TaskScheduler &&) noexcept      = default;
  TaskScheduler &operator=(const TaskScheduler &) noexcept = delete;
  TaskScheduler &operator=(TaskScheduler &&) noexcept = default;

public:
  void Scedule(int32_t _id, int32_t _time_begin, int32_t _time_end);

private:
};