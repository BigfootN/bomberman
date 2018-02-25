add_library(introduction SHARED
	intro_loop.c
	intro_views.c)

target_include_directories(introduction PUBLIC
	${CMAKE_SOURCE_DIR}/src/include/
	${CMAKE_SOURCE_DIR}/src/kernel)
