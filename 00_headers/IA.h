#ifndef IA_H
#define IA_H

//iasendmsg
void checkPlayerActif(t_etat* etat);
void sendEmail(t_etat *etat);
void CentralSend(t_etat *etat);

// ia.c
int IALooop();
void *centralIA();
// iapions.c
int checkRequete(t_etat *etat);
void movePions(t_etat* etat, t_pions *player, int type, int value);
void deadPion(t_etat *etat, t_pions *tmp);
void desactivePlayers(t_etat *etat, int numberPlayer);
void sendEndParty(t_etat* etat);
t_pions *searchPlayer(t_etat *etat, int numberPlayer);
int collision_BM(t_etat* etat, t_pions *player, int dx, int dy);
int checkAllPions(t_etat *etat);
int checkRequetePlayer(t_etat *etat);

// iamap
int serializeMap(t_etat *etat);
// iabomb.c
void initBomb(t_etat *etat, t_pions *player);
void etatBomb(t_etat *etat, t_pions *player);
//ia explosion.c
void prepaBombMap(t_etat* etat);
void displayFire(t_etat *etat, SDL_Rect lposition, int **tab);
void displayBombMap(t_control* control);
int **checkArray();
int checktuple(t_etat *etat, int tuile);
int **prepaGridFire(t_etat *etat, SDL_Rect position);
void explosionClean(t_etat* etat, int row, int col);
//iamonster
int checkWay(int **tab);
void monsterChoice(t_etat *etat, t_pions *tmp, int **tab);
int **prepaGridBonusMalus(t_etat *etat, SDL_Rect position);
t_pions *searchMonster(t_etat *etat, int numberMonster, SDL_Rect position);
void IAMonster(t_etat *etat, t_pions *tmp);
void deleteMonster(t_etat *etat, int numberMonster, SDL_Rect position);
// iagame.c
void *centralIA(void *tmp);
//iaTime
void startTime(t_etat *etat);
void difference(t_etat *etat);
//iacounter
void prepaCounterPlayer(t_etat *etat, t_player *player);
int checkCounter(t_etat *etat);
//iabonusmalus
int createBonusMalus();

#endif
