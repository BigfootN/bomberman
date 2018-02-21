cmake_minimum_required(VERSION 3.0)
project(bomberman C)
INCLUDE(FindPkgConfig)

set(CMAKE_C_COMPILER /usr/bin/gcc)

if (NOT CMAKE_BUILD_TYPE)
	SET(CMAKE_BUILD_TYPE "Debug")
endif (NOT CMAKE_BUILD_TYPE)

string(TOUPPER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE)

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

if (CMAKE_BUILD_TYPE STREQUAL "DEBUG")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
else (CMAKE_BUILD_TYPE STREQUAL "DEBUG")
	set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -O2)
endif (CMAKE_BUILD_TYPE STREQUAL "DEBUG")


pkg_check_modules(SDL sdl2 sdl)
set(SDL_HEADERS ${SDL_INCLUDE_DIRS})
set(SDL_LIB ${SDL_LIBRARIES})

add_subdirectory(${CMAKE_SOURCE_DIR}/02_noyeau)
add_subdirectory(${CMAKE_SOURCE_DIR}/03_introduction)
add_subdirectory(${CMAKE_SOURCE_DIR}/04_ipchoice)
add_subdirectory(${CMAKE_SOURCE_DIR}/05_game)
add_subdirectory(${CMAKE_SOURCE_DIR}/06_score)
add_subdirectory(${CMAKE_SOURCE_DIR}/07_network)
add_subdirectory(${CMAKE_SOURCE_DIR}/08_IA)
add_subdirectory(${CMAKE_SOURCE_DIR}/09_pictures)
add_subdirectory(${CMAKE_SOURCE_DIR}/10_lib)

message(STATUS ${SDL_INCLUDE_DIRS})

#include_directories(${SDL_INCLUDE_DIRS})

add_executable(bomberman
	${CMAKE_SOURCE_DIR}/01_main/start.c
	)

target_include_directories(bomberman PUBLIC
	${CMAKE_SOURCE_DIR}/00_headers
	${SDL_HEADERS}
	)

target_link_libraries(bomberman
	noyeau
	introduction
	ipchoice
	game
	score
	network
	IA
	pictures
	lib
	)
