#pragma once

#include "Event.hpp"

class ResponseEvent : public Event {
public:
  ResponseEvent();
  ResponseEvent(int32_t _demo_field);
  // TODO: pass parameters to form response.
public:
  void Execute() override;

private:
  int32_t demo_field; // TODO: hack
};