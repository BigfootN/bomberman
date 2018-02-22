add_library(pictures SHARED
	file.c
	initSprites.c)

target_include_directories(pictures PUBLIC ${CMAKE_SOURCE_DIR}/00_headers)
