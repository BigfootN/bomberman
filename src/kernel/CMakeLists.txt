add_library(kernel SHARED
	cleaner.c
	inits.c
	listechainee.c
	noyeau.c
	)

target_include_directories(kernel PUBLIC ${CMAKE_SOURCE_DIR}/00_headers)
