#pragma once
#include <cstdint>
#include <string>
#include <type_traits>
#include "EventHandler.hpp"

enum class EventType { TYPE_ONE = 1 << 0, TYPE_TWO = 1 << 1, TYPE_THREE = 1 << 2, COUNT };

enum class EventPeriod { NONE, YEAR, MONTH, WEEK, DAY, HOUR, MINUTE, SECOND, COUNT };

class Event {
  using Type = std::make_unsigned_t<std::underlying_type_t<EventType>>;

public:
  Event() noexcept = default;
  explicit Event(EventType _type);
  Event(EventType _type, std::string _name);
  Event(const Event &) noexcept = default;
  Event(Event &&) noexcept      = default;
  Event &operator=(const Event &) noexcept = default;
  Event &operator=(Event &&) noexcept = default;

  Event &operator=(EventType _type);

private:
  void SetName(std::string _name);
  std::string GetName() const;

public:
  /// Is any flag set?
  bool IsSet() const noexcept { return (static_cast<Type>(type) != 0); }

  /// Is the given flag set?
  bool IsSet(Type _type) const noexcept { return (static_cast<Type>(type) & _type) != 0; }

private:
  std::string name {};  // mb debug purpose
  EventType type {};
};