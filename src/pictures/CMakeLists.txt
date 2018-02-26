add_library(pictures SHARED file.c)

target_include_directories(pictures PUBLIC
	${CMAKE_SOURCE_DIR}/src/include
	${CMAKE_SOURCE_DIR}/src/introduction)
