#pragma once
#include <future>
#include <memory>
#include <queue>
#include <unordered_map>

#include "Event.hpp"

class EventManager {
public:
  EventManager();
  ~EventManager();
  EventManager(const EventManager &) noexcept = delete;
  EventManager(EventManager &&) noexcept      = default;
  EventManager &operator=(const EventManager &) noexcept = delete;
  EventManager &operator=(EventManager &&) noexcept = default;

public:
  /** Push to the queue **/
  void Push(EventType _event_type);                                 // Call when the event occurred.
  void Bind(EventType _event_type, std::unique_ptr<Event> _event);  // Call from UI.

private:
  void processEvents();  // queue.pop blocked (producer/consumer)

private:
  std::unordered_map<EventType, std::unique_ptr<Event>> events_callbacks;
  std::queue<EventType> events;

private:
  std::future<void> handler;
};