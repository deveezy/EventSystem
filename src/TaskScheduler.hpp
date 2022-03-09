#pragma once

#include <ctime>
#include <memory>

#include "Event.hpp"

class Task {
public:
  Task() = default;
  Task(std::shared_ptr<Event> _event);
  Task(std::shared_ptr<Event> _event, const std::time_t &_time_begin, const std::time_t &_time_end);

public:
  void SetEvent(std::shared_ptr<Event> _event);
  std::shared_ptr<Event> GetEvent() const;
  void SetBeginTime(const std::time_t &_time_begin);
  std::time_t GetBeginTime() const;
  void SetEndTime(const std::time_t &_time_end);
  std::time_t GetEndTime() const;

private:
  std::shared_ptr<Event> task;
  std::time_t time_begin;  // ???
  std::time_t time_end;    // ???
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
  // Bind (bind existing Event + time)
  // Create (create SP<Event> + time)
private:
};