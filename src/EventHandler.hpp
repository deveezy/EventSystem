#pragma once
#include <functional>

template <typename... Args>
class EventHandler {
private:
  using HandlerType = std::function<void(Args...)>;

public:
  void operator()(Args... args) const {
    if (handler) { handler(args...); }
  }

private:
  HandlerType handler;
};