cmake_minimum_required(VERSION 3.9)
project(bomberman)
INCLUDE(FindPkgConfig)

set(CMAKE_C_FLAGS "-g -Wall -Werror -Wextra")

add_subdirectory(src/02_kernel)
add_subdirectory(src/03_introduction)
add_subdirectory(src/04_ipchoice)
add_subdirectory(src/05_game)
add_subdirectory(src/06_scores)
add_subdirectory(src/18_network)
add_subdirectory(src/19_ia)
add_subdirectory(src/20_pictures)
add_subdirectory(src/21_libs)
add_subdirectory(res/map)
add_subdirectory(res/roboto)
add_subdirectory(res/sprites)

pkg_check_modules(SDL2 REQUIRED sdl2 SDL2_image SDL2_ttf)
find_package (Threads)

add_executable(bomberman
	${CMAKE_SOURCE_DIR}/src/01_main/bomberman.c
	)

target_link_libraries(bomberman
	${SDL2_LIBRARIES}
	${CMAKE_THREAD_LIBS_INIT}
	kernel
	introduction
	ipchoice
	game
	scores
	network
	ia
	pictures
	libs
	)

target_include_directories(bomberman PUBLIC
	${SDL2_INCLUDE_DIRS}
	${CMAKE_SOURCE_DIR}/src/01_main
	${CMAKE_SOURCE_DIR}/src/02_kernel
	${CMAKE_SOURCE_DIR}/src/03_introduction
	${CMAKE_SOURCE_DIR}/src/04_ipchoice
	${CMAKE_SOURCE_DIR}/src/05_game
	${CMAKE_SOURCE_DIR}/src/18_network
	${CMAKE_SOURCE_DIR}/src/19_ia
	${CMAKE_SOURCE_DIR}/src/20_pictures
	)
