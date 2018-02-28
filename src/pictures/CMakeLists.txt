add_library(pictures SHARED
	file.c
	sprites.c
	)

target_include_directories(pictures PUBLIC
	${CMAKE_SOURCE_DIR}/src/include/
	${CMAKE_SOURCE_DIR}/src/intro
	)
