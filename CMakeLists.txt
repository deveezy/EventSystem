cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(EventSystem)

add_executable(${CMAKE_PROJECT_NAME} 
	src/common/Flags.hpp
	src/EventManager.hpp
	src/EventManager.cpp
	src/EventHandler.hpp
	src/EventHandler.cpp
	src/Event.hpp
	src/Event.cpp
	src/ConcurrentQueue.hpp
	src/main.cpp
)