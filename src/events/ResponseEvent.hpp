#pragma once

#include "../Event.hpp"

class ResponseEvent : public Event {
public:
  void Execute() override;
};