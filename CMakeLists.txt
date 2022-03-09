cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(EventSystem)

add_executable(${CMAKE_PROJECT_NAME} 
	src/common/Flags.hpp

	src/EventManager.hpp
	src/EventManager.cpp
	src/TaskScheduler.hpp
	src/TaskScheduler.cpp

	src/Event.hpp
	src/Event.cpp

	src/ConcurrentQueue.hpp

	src/events/DayNightEvent.cpp
	src/events/ResponseEvent.cpp

	src/main.cpp
)