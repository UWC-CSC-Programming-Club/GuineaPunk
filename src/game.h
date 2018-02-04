#ifndef LINUX_LIMITS
#include <linux/limits.h>
#define LINUX_LIMITS
#endif

#define GAME_N_MAX 50

#define GENRE_ACTION 1
#define GENRE_ADVENTURE 2
#define GENRE_RPG 3

typedef struct gameData {
	char path[PATH_MAX];
	char name[GAME_N_MAX];
	char author[GAME_N_MAX];
	int length;
	int genre;
} gameData;