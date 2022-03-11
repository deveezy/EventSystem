#include "TaskScheduler.hpp"

TaskScheduler::TaskScheduler() = default;

TaskScheduler::~TaskScheduler() = default;

void TaskScheduler::Push(Trigger _trigger, std::shared_ptr<Task> _task) {
  tasks.emplace(_trigger, _task);
}

int32_t TaskScheduler::Acquire(Trigger _trigger) {
  for (const auto &it : tasks) {
    if (it.first & _trigger) {
      if (it.second->GetShedType() == SchedType::ALWAYS) return it.second->GetBoundedId();
      // TODO: get current time and compare with range inside it.second.
      uint64_t curr_time = 1337;
      if (curr_time >= it.second->GetTimeBegin() && curr_time <= it.second->GetTimeEnd()) {
        /// Assume we found needed task.
        return it.second->GetBoundedId();
      }
    }
  }
  return -1;
}
