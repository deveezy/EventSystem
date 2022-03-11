cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(EventSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)

add_subdirectory(src/sqlite)

add_executable(${CMAKE_PROJECT_NAME}
	src/common/Flags.hpp
	src/common/Datatypes.hpp

	src/EventManager.hpp
	src/EventManager.cpp
	src/TaskScheduler.hpp
	src/TaskScheduler.cpp

	src/ConcurrentQueue.hpp

	src/events/Event.hpp
	src/events/Event.cpp

	src/tasks/Task.hpp
	src/tasks/Task.cpp

	src/tools/DBGenerator.cpp
	src/tools/DBManager.cpp
	src/tools/Macro.cpp

	src/main.cpp
)
message(STATUS ${CMAKE_PROJECT_NAME})

target_link_libraries(${CMAKE_PROJECT_NAME} sqlite)