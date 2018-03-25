cmake_minimum_required(VERSION 3.0)
project(bomberman C)
#INCLUDE(FindPkgConfig)

#set(CMAKE_C_FLAGS "-pg -g -Wall -Werror -Wextra")

set(KERNEL_SRC
        ${CMAKE_SOURCE_DIR}/src/02_kernel/chainedlist.c
        ${CMAKE_SOURCE_DIR}/src/02_kernel/inits.c
        ${CMAKE_SOURCE_DIR}/src/02_kernel/kernel.c
        )

set(INTRO_SRC
        ${CMAKE_SOURCE_DIR}/src/03_introduction/introloop.c
        ${CMAKE_SOURCE_DIR}/src/03_introduction/introviews.c
        )

set(MAIN_SRC
        ${CMAKE_SOURCE_DIR}/src/01_main/bomberman.c
        )

set(IP_CHOICE_SRC
        ${CMAKE_SOURCE_DIR}/src/04_ipchoice/choiceiploop.c
        ${CMAKE_SOURCE_DIR}/src/04_ipchoice/choiceipwindow.c
        ${CMAKE_SOURCE_DIR}/src/04_ipchoice/choicepviews.c
        )

set(GAME_SRC
        ${CMAKE_SOURCE_DIR}/src/05_game/display_game.c
        ${CMAKE_SOURCE_DIR}/src/05_game/loop_game.c
        ${CMAKE_SOURCE_DIR}/src/05_game/panel_game.c
        ${CMAKE_SOURCE_DIR}/src/05_game/time_game.c
        ${CMAKE_SOURCE_DIR}/src/05_game/views_game.c
        )

set(SCORES_SRC
        ${CMAKE_SOURCE_DIR}/src/06_scores/scrviews.c
        ${CMAKE_SOURCE_DIR}/src/06_scores/srcloop.c
        )

set(NETWORK_SRC
        ${CMAKE_SOURCE_DIR}/src/18_network/network_player.c
        ${CMAKE_SOURCE_DIR}/src/18_network/network.c
        ${CMAKE_SOURCE_DIR}/src/18_network/tcpclient.c
        ${CMAKE_SOURCE_DIR}/src/18_network/tcpserver.c
        )

set(IA_SRC
        ${CMAKE_SOURCE_DIR}/src/19_ia/ia.c
        ${CMAKE_SOURCE_DIR}/src/19_ia/ia_bolus_malus.c
        ${CMAKE_SOURCE_DIR}/src/19_ia/ia_bomb.c
        ${CMAKE_SOURCE_DIR}/src/19_ia/ia_counter.c
        ${CMAKE_SOURCE_DIR}/src/19_ia/ia_dead.c
        ${CMAKE_SOURCE_DIR}/src/19_ia/ia_explosion.c
        ${CMAKE_SOURCE_DIR}/src/19_ia/ia_map.c
        ${CMAKE_SOURCE_DIR}/src/19_ia/ia_monster.c
        ${CMAKE_SOURCE_DIR}/src/19_ia/ia_pions.c
        ${CMAKE_SOURCE_DIR}/src/19_ia/ia_send_msg.c
        ${CMAKE_SOURCE_DIR}/src/19_ia/ia_timer.c
        ${CMAKE_SOURCE_DIR}/src/19_ia/ia_party.c
        )

set(PICTURES_SRC
        ${CMAKE_SOURCE_DIR}/src/20_pictures/file.c
        ${CMAKE_SOURCE_DIR}/src/20_pictures/init_sprites.c
        ${CMAKE_SOURCE_DIR}/src/20_pictures/searchdirectory.c
        )

set(LIBS_SRC
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_put_nbr.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_putchar.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_putstr.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_rand.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_strcat.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_strcmp.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_strdup.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_string.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_strlen.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_bzero.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_memset.c
        )

add_subdirectory(res/map)
add_subdirectory(res/roboto)
add_subdirectory(res/sprites)

#pkg_check_modules(SDL2 REQUIRED sdl2 SDL2_image SDL2_ttf)
#find_package (Threads)

add_executable(bomberman
        ${KERNEL_SRC}
        ${INTRO_SRC}
        ${MAIN_SRC}
        ${IP_CHOICE_SRC}
        ${GAME_SRC}
        ${SCORES_SRC}
        ${NETWORK_SRC}
        ${IA_SRC}
        ${PICTURES_SRC}
        ${LIBS_SRC}
        )

target_link_libraries(bomberman mingw32 SDL2main SDL2 SDL2_image SDL2_ttf
        #${SDL2_LIBRARIES}
        #${CMAKE_THREAD_LIBS_INIT}
        )

target_include_directories(bomberman PUBLIC
        ${SDL2_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/src/00_headers
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
