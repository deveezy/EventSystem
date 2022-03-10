#pragma once
#include <cstdint>
#include <string>
#include <type_traits>

#include "../common/Datatypes.hpp"

class Event {
public:
  Event() noexcept = default;
  Event(Action _action, Trigger _event_type);
  Event(Action _type, std::string _name);
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
  void SetActionType(Action _action);
  Flags<Action> GetActionType() const;
  void SetTriggerType(Trigger _event_type);
  Flags<Trigger> GetTriggerType() const;

protected:
  std::string name {};  // mb debug purpose
  Flags<Action> action_type {};
  Flags<Trigger> event_type {};
};