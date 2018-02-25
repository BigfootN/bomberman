add_library(network SHARED
	addNetworkPlayer.c
	network.c
	tcpclient.c
	tcpserver.c tcpserver.h)

target_include_directories(network PUBLIC ${CMAKE_SOURCE_DIR}/src/include/)
target_include_directories(network PUBLIC ${CMAKE_SOURCE_DIR}/src/kernel/)
