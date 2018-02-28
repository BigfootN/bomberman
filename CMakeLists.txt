cmake_minimum_required(VERSION 3.0)
project(bomberman C)
INCLUDE(FindPkgConfig)

set(CMAKE_C_COMPILER /usr/bin/gcc)

if (NOT CMAKE_BUILD_TYPE)
	SET(CMAKE_BUILD_TYPE "Debug")
endif (NOT CMAKE_BUILD_TYPE)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

string(TOUPPER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE)

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

if (CMAKE_BUILD_TYPE STREQUAL "DEBUG")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
else (CMAKE_BUILD_TYPE STREQUAL "DEBUG")
	set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -O2)
endif (CMAKE_BUILD_TYPE STREQUAL "DEBUG")


pkg_check_modules(SDL sdl2 sdl SDL2_ttf SDL2_image)
set(SDL_HEADERS ${SDL_INCLUDE_DIRS})
set(SDL_LIB ${SDL_LIBRARIES})

add_subdirectory(${CMAKE_SOURCE_DIR}/src/kernel)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/intro)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/ipchoice)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/game)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/score)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/network)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/ai)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/pictures)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/lib)
#add_subdirectory(${CMAKE_SOURCE_DIR}/src/memory)

message(STATUS ${SDL_INCLUDE_DIRS})

#include_directories(${SDL_INCLUDE_DIRS})

add_executable(bomberman
	${CMAKE_SOURCE_DIR}/src/bomberman.c
	)

target_link_libraries(bomberman
	kernel
	introduction
	ipchoice
	game
	score
	network
	ai
	pictures
	)
