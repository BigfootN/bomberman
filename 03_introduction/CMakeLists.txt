add_library(introduction SHARED
	introloop.c
	introviews.c)

target_include_directories(introduction PUBLIC ${CMAKE_SOURCE_DIR}/00_headers)
