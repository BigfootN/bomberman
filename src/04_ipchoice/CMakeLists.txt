add_library(ipchoice SHARED
	choiceiploop.c
	choiceipwindow.c
	choicepviews.c)

target_include_directories(ipchoice PUBLIC ${CMAKE_SOURCE_DIR}/src/include/)
