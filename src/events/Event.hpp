#pragma once
#include <cstdint>
#include <string>
#include <type_traits>

#include "../common/Datatypes.hpp"

class Event {
public:
  Event() noexcept = default;
  Event(ActionType _action_type, TriggerType _event_type);
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
  void SetTriggerType(TriggerType _event_type);
  Flags<TriggerType> GetTriggerType() const;

protected:
  std::string name {};  // mb debug purpose
  Flags<ActionType> action_type {};
  Flags<TriggerType> event_type {};
};