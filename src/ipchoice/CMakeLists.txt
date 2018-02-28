add_library(ipchoice SHARED
	choice_ip_loop.c
	choice_ip_window.c
	choice_ip_views.c)

target_include_directories(ipchoice PUBLIC
	${CMAKE_SOURCE_DIR}/src/include/
	${CMAKE_SOURCE_DIR}/src/kernel/
	)
