add_library(game SHARED
        display_game.c
        loop_game.c
        panel_game.c
        time_game.c
        views_game.c
        )

target_include_directories(game PUBLIC
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

