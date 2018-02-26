add_library(kernel SHARED
	inits.c
	linked_list.c
	kernel.c
	)

target_include_directories(kernel PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
