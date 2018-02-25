add_library(lib SHARED
	my_put_nbr.c
	my_putchar.c
	my_putstr.c
	my_rand.c
	my_strcat.c
	my_strcmp.c
	my_strdup.c
	my_string.c
	my_strlen.c)

target_include_directories(lib PUBLIC ${CMAKE_SOURCE_DIR}/src/include/)

get_directory_property(SDL_HEADERS DIRECTORY ${CMAKE_SOURCE_DIR} DEFINITION SDL_HEADERS)
get_directory_property(SDL_LIB DIRECTORY ${CMAKE_SOURCE_DIR} DEFINITION SDL_LIB)

target_include_directories(lib PUBLIC ${CMAKE_SOURCE_DIR}/src/include/ ${SDL_HEADERS})
target_link_libraries(lib ${SDL_LIB})
