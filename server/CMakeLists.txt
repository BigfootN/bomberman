cmake_minimum_required(VERSION 3.0)

project(BombermanServer C)

set(CMAKE_C_COMPILER /usr/bin/gcc)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "debug")
endif (NOT CMAKE_BUILD_TYPE)

string(TOLOWER "${CMAKE_BUILD_TYPE}" BUILD_TYPE_LOW)

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

if (BUILD_TYPE_LOW STREQUAL "debug")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
elseif (BUILD_TYPE_LOW STREQUAL "release")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
endif (BUILD_TYPE_LOW STREQUAL "debug")

add_subdirectory(
	src
	)
