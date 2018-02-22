add_library(ipchoice SHARED
	choiceiploop.c
	choiceipwindow.c
	choicepviews.c)

target_include_directories(introduction PUBLIC ${CMAKE_SOURCE_DIR}/00_headers)
