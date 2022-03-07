#pragma once

#include "../Event.hpp"

class ResponseEvent : public Event {
public:
  ResponseEvent();
  // TODO: pass parameters to form response.
public:
  void Execute() override;
};