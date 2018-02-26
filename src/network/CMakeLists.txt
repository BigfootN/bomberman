add_library(network SHARED
	addNetworkPlayer.c
	network.c
	tcpclient.c
	tcpserver.c)

target_include_directories(network PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
