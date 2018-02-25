add_library(ia SHARED
	ai.c
	ai_bomb.c
	ai_blast.c
	ai_bonus_penalty.c
	ai_counter.c
	ai_dead.c
	ai_map.c
	ai_monster.c
	ai_piece.c
	ai_msg.c
	ai_timer.c ai_msg.h)

target_include_directories(ia PUBLIC ${CMAKE_SOURCE_DIR}/src/include/)
target_include_directories(ia PUBLIC ${CMAKE_SOURCE_DIR}/src/kernel/)
