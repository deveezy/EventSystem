#include "ResponseEvent.hpp"

#include <iostream>

ResponseEvent::ResponseEvent(int32_t _demo_field)
    : Event {ActionType::RESPONSE, "RESPONSE"}
    , demo_field {_demo_field} {}

void ResponseEvent::Execute() { std::cout << name << "\n"; }
