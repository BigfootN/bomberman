add_library(score SHARED
	score_views.c
	score_loop.c)

target_include_directories(score PUBLIC
	${CMAKE_SOURCE_DIR}/src/include/
	${CMAKE_SOURCE_DIR}/src/game
	${CMAKE_SOURCE_DIR}/src/kernel
	)
