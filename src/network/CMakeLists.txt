add_library(network SHARED
	add_network_player.c
	network.c
	tcp_client.c
	tcp_server.c)

target_include_directories(network PUBLIC
	${CMAKE_SOURCE_DIR}/src/include/
	${CMAKE_SOURCE_DIR}/src/kernel/
	${CMAKE_SOURCE_DIR}/src/ai/
	)
