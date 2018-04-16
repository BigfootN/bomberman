cmake_minimum_required(VERSION 3.10)
project(bomberman)
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    INCLUDE(FindPkgConfig)
endif (CMAKE_SYSTEM_NAME STREQUAL "Linux")

set(CMAKE_C_FLAGS "-pg -g -Wall -Werror -Wextra")

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})

include_directories(HEADER_FILES INTERFACE ${CMAKE_SOURCE_DIR}/src/00_headers/)

set(MAIN_SRC
        ${CMAKE_SOURCE_DIR}/src/01_main/bomberman.c
        )

set(KERNEL_SRC
        ${CMAKE_SOURCE_DIR}/src/02_kernel/inits.c
        ${CMAKE_SOURCE_DIR}/src/02_kernel/chainedlist.c
        ${CMAKE_SOURCE_DIR}/src/02_kernel/kernel.c
        )

set(INTRO_SRC
        ${CMAKE_SOURCE_DIR}/src/03_introduction/introloop.c
        ${CMAKE_SOURCE_DIR}/src/03_introduction/introviews.c
        )

set(IP_CHOICE_SRC
        ${CMAKE_SOURCE_DIR}/src/04_ipchoice/choiceiploop.c
        ${CMAKE_SOURCE_DIR}/src/04_ipchoice/choiceipwindow.c
        ${CMAKE_SOURCE_DIR}/src/04_ipchoice/choicepviews.c
        )

set(PREPA_GAME_SRC
        ${CMAKE_SOURCE_DIR}/src/04_prepa_game/display_prepagame.c
        ${CMAKE_SOURCE_DIR}/src/04_prepa_game/loop_prepagame.c
        ${CMAKE_SOURCE_DIR}/src/04_prepa_game/write_prepa_game.c
        )

set(GAME_SRC
        ${CMAKE_SOURCE_DIR}/src/05_game/display_game.c
        ${CMAKE_SOURCE_DIR}/src/05_game/loop_game.c
        ${CMAKE_SOURCE_DIR}/src/05_game/panel_game.c
        ${CMAKE_SOURCE_DIR}/src/05_game/time_game.c
        ${CMAKE_SOURCE_DIR}/src/05_game/views_game.c
        )

set(NETWORK_SRC
        ${CMAKE_SOURCE_DIR}/src/18_network/tcp_client.c
        ${CMAKE_SOURCE_DIR}/src/18_network/tcp_server.c
        ${CMAKE_SOURCE_DIR}/src/18_network/network.c
        ${CMAKE_SOURCE_DIR}/src/18_network/network_player.c
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
        ${CMAKE_SOURCE_DIR}/src/20_pictures/map.c
        ${CMAKE_SOURCE_DIR}/src/20_pictures/annexe_directory.c
        ${CMAKE_SOURCE_DIR}/src/20_pictures/init_pictures.c
        )

set(LIBS_SRC
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_bzero.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_put_nbr.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_putchar.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_putstr.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_rand.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_strcat.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_strcmp.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_strdup.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_string.c
        ${CMAKE_SOURCE_DIR}/src/21_libs/my_strlen.c
        )

add_subdirectory(res/maps)
add_subdirectory(res/fonts)
add_subdirectory(res/pictures)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_package(Threads)
    pkg_check_modules(SDL2 REQUIRED sdl2 SDL2_image SDL2_ttf)
endif (CMAKE_SYSTEM_NAME STREQUAL "Linux")

add_executable(bomberman
        ${MAIN_SRC}
        ${KERNEL_SRC}
        ${INTRO_SRC}
        ${IP_CHOICE_SRC}
        ${PREPA_GAME_SRC}
        ${GAME_SRC}
        ${NETWORK_SRC}
        ${IA_SRC}
        ${LIBS_SRC}
        ${PICTURES_SRC}
        ${HEADER_FILES}
        )
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(bomberman mingw32 pthread SDL2main SDL2 SDL2_image SDL2_ttf wsock32 ws2_32)
endif (CMAKE_SYSTEM_NAME STREQUAL "Windows")

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(bomberman
            ${SDL2_LIBRARIES}
            ${SDL2TTF_LIBRARIES}
            ${SDL2IMG_LIBRARIES}
            ${CMAKE_THREAD_LIBS_INIT}
            )
endif (CMAKE_SYSTEM_NAME STREQUAL "Linux")

target_include_directories(bomberman PUBLIC
        ${SDL2_INCLUDE_DIRS}
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
