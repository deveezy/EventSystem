#pragma once
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>

template <class Data>
class ConcurrentQueue {
public:
  ConcurrentQueue(size_t _max_size) : max_size(_max_size) {}
  ConcurrentQueue(const ConcurrentQueue &) noexcept = delete;
  ConcurrentQueue(ConcurrentQueue &&) noexcept      = default;
  ConcurrentQueue &operator=(const ConcurrentQueue &) noexcept = delete;
  ConcurrentQueue &operator=(ConcurrentQueue &&) noexcept = default;

public:
  bool TryPush(const Data &_data) {
    std::lock_guard<std::mutex> lock(mtx);
    if (queue.size() >= max_size) return false;
    queue.push(_data);
    cond_var.notify_one();
    return true;
  }

  bool Empty() const {
    std::lock_guard<std::mutex> lock(mtx);
    return queue.empty();
  }

  bool TryPop(Data &popped_value) {
    std::lock_guard<std::mutex> lock(mtx);
    if (queue.empty()) { return false; }
    popped_value = queue.front();
    queue.pop();
    return true;
  }

  void Clear() {
    std::lock_guard<std::mutex> lock(mtx);
    while (!queue.empty()) { queue.front(); }
  }

  void WaitAndPop(Data &popped_value) {
    std::unique_lock<std::mutex> lock(mtx);
    while (queue.empty()) { cond_var.wait(lock); }
    popped_value = queue.front();
    queue.pop();
  }

  bool WaitTimeAndTryPop(Data &popped_value, const std::chrono::milliseconds &timeout) {
    std::unique_lock<std::mutex> lock(mtx);
    while (queue.empty()) {
      auto status = cond_var.wait_for(lock, timeout);
      if (status == std::cv_status::timeout) return false;
    }
    popped_value = queue.front();
    queue.pop();
    return true;
  }

private:
  std::queue<Data> queue;
  mutable std::mutex mtx;
  std::condition_variable cond_var;
  size_t max_size;
};
