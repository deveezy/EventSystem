#pragma once

#include <ctime>
#include <map>
#include <memory>

#include "tasks/Task.hpp"

class TaskScheduler {
public:
  TaskScheduler();
  ~TaskScheduler();
  TaskScheduler(const TaskScheduler &) noexcept = delete;
  TaskScheduler(TaskScheduler &&) noexcept      = default;
  TaskScheduler &operator=(const TaskScheduler &) noexcept = delete;
  TaskScheduler &operator=(TaskScheduler &&) noexcept = default;

public:
  void Push(Trigger _trigger, std::shared_ptr<Task> _task);
  int32_t Acquire(Trigger _trigger); // return bounded id

private:
  std::multimap<Trigger, std::shared_ptr<Task>> tasks;
};