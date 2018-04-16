add_library(network SHARED
	network.c
	tcp_client.c
	)


target_include_directories(network PUBLIC
		${CMAKE_SOURCE_DIR}/src/00_headers
		${CMAKE_SOURCE_DIR}/src/01_main
		${CMAKE_SOURCE_DIR}/src/02_kernel
		${CMAKE_SOURCE_DIR}/src/03_introduction
		${CMAKE_SOURCE_DIR}/src/04_ipchoice
		${CMAKE_SOURCE_DIR}/src/04_prepa_game
		${CMAKE_SOURCE_DIR}/src/05_game
		${CMAKE_SOURCE_DIR}/src/18_network
		${CMAKE_SOURCE_DIR}/src/19_ia
		${CMAKE_SOURCE_DIR}/src/20_pictures
		${CMAKE_SOURCE_DIR}/src/21_libs
	)

