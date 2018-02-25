add_library(game SHARED
	gameDisplay.c
	gameLoop.c
	gamePanels.c
	gameTime.c
		game_views.c game_views.h)

get_directory_property(SDL_HEADERS DIRECTORY ${CMAKE_SOURCE_DIR} DEFINITION SDL_HEADERS)
get_directory_property(SDL_LIB DIRECTORY ${CMAKE_SOURCE_DIR} DEFINITION SDL_LIB)

target_include_directories(game PUBLIC ${CMAKE_SOURCE_DIR}/src/include/ ${SDL_HEADERS})
target_link_libraries(game ${SDL_LIB})
