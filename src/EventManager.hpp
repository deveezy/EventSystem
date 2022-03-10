#pragma once
#include <future>
#include <memory>
#include <unordered_map>

#include "ConcurrentQueue.hpp"
#include "TaskScheduler.hpp"
#include "events/Event.hpp"


class EventManager {
public:
  EventManager();
  ~EventManager();
  EventManager(const EventManager &) noexcept = delete;
  EventManager(EventManager &&) noexcept      = delete;
  EventManager &operator=(const EventManager &) noexcept = delete;
  EventManager &operator=(EventManager &&) noexcept = delete;

public:
  /// Reactions
  void CreateActionDay(std::string _name, bool _ir, bool _wb);
  void CreateActionNight(std::string _name, bool _ir, bool _wb);
  void CreateActionIR(std::string _name, uint32_t _seconds);
  void CreateActionVideoRecord(std::string _name, uint32_t _seconds);
  /// ---------------------------------------------------------

  void Bind(Trigger _trigger, Action _action, int32_t _action_id);
  void Unbind(int32_t _id);
  void Exclude(int32_t _id, Trigger _trigger);
  void EnableTrigger(int32_t _id, bool _enable);

  void Schedule(int32_t _id, SchedType _sched_type, uint64_t _begin = 0, uint64_t _end = 0);

  void Push(Trigger _trigger);

private:
  void processEvents();

private:
  std::unordered_map<uint32_t, std::shared_ptr<Event>> event_actions;
  ConcurrentQueue<int32_t> events;
  TaskScheduler scheduler;

private:
  std::future<void> handler;
};