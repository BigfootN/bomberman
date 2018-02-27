add_library(memory SHARED
	memory.c
	)

target_include_directories(memory PUBLIC
	${CMAKE_SOURCE_DIR}/src/include
	)
