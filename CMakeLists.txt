cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(EventSystem)

add_executable(${CMAKE_PROJECT_NAME} 
	src/EventHandler.hpp
	src/EventHandler.cpp
	src/Event.hpp
	src/Event.cpp
	src/main.cpp
)