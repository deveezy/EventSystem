#pragma once
#include <cstdint>
#include <string>
#include <type_traits>

#include "common/Flags.hpp"

enum class EventType {
  DETECTOR_NIGHT = 1 << 0,
  DETECTOR_DAY   = 1 << 1,
  MOTION         = 1 << 2,

  COUNT
};
enum class ActionType { RESPONSE = 1, DAY_NIGNT, IR };
ENUM_FLAGS(EventType)
ENUM_FLAGS(ActionType)

class Event {
public:
  Event() noexcept = default;
  Event(ActionType _action_type, EventType _event_type);
  Event(ActionType _type, std::string _name);
  Event(const Event &) noexcept = default;
  Event(Event &&) noexcept      = default;
  Event &operator=(const Event &) noexcept = default;
  Event &operator=(Event &&) noexcept = default;
  virtual ~Event()                    = default;

public:
  virtual void Execute() = 0;

public:
  void SetName(std::string _name);
  std::string GetName() const;
  void SetActionType(ActionType _action_type);
  Flags<ActionType> GetActionType() const;
  void SetEventType(EventType _event_type);
  Flags<EventType> GetEventType() const;

protected:
  std::string name {};  // mb debug purpose
  Flags<ActionType> action_type {};
  Flags<EventType> event_type {};
};