add_library(ai SHARED
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
	ai_timer.c
	)

target_include_directories(ai PUBLIC
	${CMAKE_SOURCE_DIR}/src/include/
	${CMAKE_SOURCE_DIR}/src/kernel/
	${CMAKE_SOURCE_DIR}/src/pictures/
	${CMAKE_SOURCE_DIR}/src/network/
	)
