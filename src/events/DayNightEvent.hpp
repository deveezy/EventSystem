#pragma once
#include "../Event.hpp"

class DayNightEvent : public Event {
public:
  enum class Mode { DAY = 1, NIGHT };

public:
  DayNightEvent();
  DayNightEvent(Mode _mode);
  // TODO: pass parameters to form rules of daynight toggling.
public:
  void Execute() override;

public:
	void SetMode(Mode _mode);
	Mode GetMode() const;

private:
  Mode mode;
};