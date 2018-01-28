#include <linux/limits.h>

#define GAME_N_MAX 50

#define GENRE_ACTION 1
#define GENRE_ADVENTURE 2
#define GENRE_RPG 3

struct game {
	char path[PATH_MAX];
	char name[GAME_N_MAX];
	char author[GAME_N_MAX];
	int length;
	int genre;
};