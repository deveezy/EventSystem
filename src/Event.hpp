#pragma once
#include <cstdint>
#include <string>
#include <type_traits>

#include "EventHandler.hpp"
#include "common/Flags.hpp"

enum class EventType { TYPE_ONE = 1 << 0, TYPE_TWO = 1 << 1, TYPE_THREE = 1 << 2, COUNT };
ENUM_FLAGS(EventType)

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
  virtual ~Event()                    = default;

public:
  virtual void Execute() = 0;

private:
  void SetName(std::string _name);
  std::string GetName() const;
  void SetType(EventType _type);
  common::Flags<EventType> GetType() const;

private:
  std::string name {};  // mb debug purpose
  common::Flags<EventType> type {};
};