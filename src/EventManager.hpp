#pragma once
#include <future>
#include <memory>
#include <unordered_map>

#include "ConcurrentQueue.hpp"
#include "Event.hpp"

class EventManager {
public:
  EventManager();
  ~EventManager();
  EventManager(const EventManager &) noexcept = delete;
  EventManager(EventManager &&) noexcept      = delete;
  EventManager &operator=(const EventManager &) noexcept = delete;
  EventManager &operator=(EventManager &&) noexcept = delete;

public:
  /** Push to the queue **/
  void Push(Flags<EventType> _event_type);
  std::shared_ptr<Event> CreateEvent(ActionType _action_type);
  void Bind(Flags<EventType> _event_type, std::shared_ptr<Event> _event);  // Call from UI.
  void Unbind(uint32_t _id, Flags<EventType> _event_type);                 // Call from UI.
  void Exclude(uint32_t _id, Flags<EventType> _event_type);

private:
  void processEvents();  // queue.pop blocked (producer/consumer)
  void initEvents();

private:
  // NOTE: mb key will be Task class with id and info about time
  std::unordered_map<uint32_t, std::shared_ptr<Event>> event_actions;
  ConcurrentQueue<EventType> events;

private:
  std::future<void> handler;
};