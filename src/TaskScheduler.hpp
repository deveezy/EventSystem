#pragma once

#include <ctime>
#include <memory>
#include <unordered_map>
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

private:
  std::unordered_map<uint32_t, std::shared_ptr<Task>> tasks;
};