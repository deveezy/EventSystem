#include "Task.hpp"

Task::Task(int32_t _bounded_id, SchedType _sched_type, uint64_t _time_begin, uint64_t _time_end)
    : bounded_id {_bounded_id}
    , sched_type {_sched_type}
    , time_begin {_time_begin}
    , time_end {_time_end} {}

int32_t Task::GetBoundedId() const { return bounded_id; }

void Task::SetBoundedId(int32_t _bounded_id) { bounded_id = _bounded_id; }

SchedType Task::GetShedType() const { return sched_type; }

void Task::SetSchedType(SchedType _sched_type) { sched_type = _sched_type; }

uint64_t Task::GetTimeBegin() const { return time_begin; }

void Task::SetTimeBegin(uint64_t _time_begin) { time_begin = _time_begin; }

uint64_t Task::GetTimeEnd() const { return time_end; }

void Task::SetTimeEnd(uint64_t _time_end) { time_end = _time_end; }
