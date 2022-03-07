#pragma once
#include <cstdint>
#include <string>
#include <type_traits>

#include "EventHandler.hpp"
#include "common/Flags.hpp"

enum class EventType { MOTION = 1 << 0, AUTO_FOCUS = 1 << 1, TEMPERATURE = 1 << 2, COUNT };
enum class ActionType { RESPONSE, DAY_NIGNT, IR};
ENUM_FLAGS(EventType)

class Event {
  using Type = std::make_unsigned_t<std::underlying_type_t<EventType>>;

public:
  Event() noexcept = default;
  explicit Event(ActionType _type);
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
  void SetType(ActionType _type);
  ActionType GetType() const;

protected:
  std::string name {};  // mb debug purpose
  ActionType action_type {};
};