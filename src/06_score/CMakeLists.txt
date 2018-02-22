add_library(score SHARED
	scrviews.c
	srcloop.c)

target_include_directories(score PUBLIC ${CMAKE_SOURCE_DIR}/00_headers)
