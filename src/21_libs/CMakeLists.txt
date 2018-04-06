add_library(libs SHARED
	my_put_nbr.c
	my_putchar.c
	my_putstr.c
	my_rand.c
	my_strcat.c
	my_strcmp.c
	my_strdup.c
	my_string.c
	my_strlen.c
		my_bzero.c
	)

target_include_directories(libs PUBLIC
	${CMAKE_SOURCE_DIR}/src/01_main
	${CMAKE_SOURCE_DIR}/src/02_kernel
	${CMAKE_SOURCE_DIR}/src/03_introduction
	${CMAKE_SOURCE_DIR}/src/04_ipchoice
	${CMAKE_SOURCE_DIR}/src/05_game
	${CMAKE_SOURCE_DIR}/src/06_scores
	${CMAKE_SOURCE_DIR}/src/18_network
	${CMAKE_SOURCE_DIR}/src/19_ia
	${CMAKE_SOURCE_DIR}/src/20_pictures
	${CMAKE_SOURCE_DIR}/src/21_libs
	)
