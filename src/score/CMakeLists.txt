add_library(score SHARED
	scrviews.c
	srcloop.c)

target_include_directories(introduction PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
