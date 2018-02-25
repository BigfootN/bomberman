add_library(game SHARED
	game_display.c
	game_loop.c
	game_panels.c
	game_time.c
	game_views.c)

get_directory_property(SDL_HEADERS DIRECTORY ${CMAKE_SOURCE_DIR} DEFINITION SDL_HEADERS)
get_directory_property(SDL_LIB DIRECTORY ${CMAKE_SOURCE_DIR} DEFINITION SDL_LIB)

target_include_directories(game PUBLIC
	${CMAKE_SOURCE_DIR}/src/include/
	${CMAKE_SOURCE_DIR}/src/kernel/
	${CMAKE_SOURCE_DIR}/src/network/
	${CMAKE_SOURCE_DIR}/src/ai/
	${SDL_HEADERS})
target_link_libraries(game ${SDL_LIB})
