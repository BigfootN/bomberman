add_library(ia SHARED
        ia.c
        ia_bolus_malus.c
        ia_bomb.c
        ia_map.c
        ia_monster.c
        ia_pions.c
        ia_send_msg.c
        ia_timer.c
        ia_counter.c
        ia_explosion.c
        )

target_include_directories(ia PUBLIC
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
