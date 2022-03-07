#include "ResponseEvent.hpp"

#include <iostream>


ResponseEvent::ResponseEvent() : Event {ActionType::RESPONSE, "RESPONSE"} {}

void ResponseEvent::Execute() { std::cout << name << "\n"; }
