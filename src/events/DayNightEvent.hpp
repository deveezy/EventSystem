#pragma once
#include "../Event.hpp"

class DayNightEvent : public Event {
public:
	DayNightEvent();
	// TODO: pass parameters to form rules of daynight toggling.
public:
	void Execute() override;
};