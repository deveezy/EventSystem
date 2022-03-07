#pragma once
#include "../Event.hpp"

class DayNightEvent : public Event {
public:
	void Execute() override;
};