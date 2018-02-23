add_library(ia SHARED
	IA.c
	IABomb.c
	IABonusMalus.c
	IACounter.c
	IADead.c
	IAExplosion.c
	IAmap.c
	IAmonster.c
	IApions.c
	IAsendMsg.c
	IATimer.c
	initSprites.c)

target_include_directories(ia PUBLIC ${CMAKE_SOURCE_DIR}/00_headers)
