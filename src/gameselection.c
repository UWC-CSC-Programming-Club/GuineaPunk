#ifndef GAMESELECTION
#include "gameselection.h"
#define GAMESELECTION
#endif

#ifndef GAME
#include "game.h"
#define GAME
#endif

#ifndef DIRENT
#include <dirent.h>
#define DIRENT
#endif

#ifndef STDIO
#include <stdio.h>
#define STDIO
#endif

#ifndef STRING
#include <string.h>
#define STRING
#endif

#ifndef STDLIB
#include <stdlib.h>
#define STDLIB
#endif

#define GAMES_PATH "./games/"

char* substrFromIndexToChar(char* string, int length, int index, char lastCharacter) {
	char* outptr = (char*)malloc(length * sizeof(char));
	int i, j;
	for (i = index, j = 0; *(string + i) != lastCharacter; i++, j++) {
		*(outptr + j) = *(string + i);
		*(outptr + j + 1) = '\0';
	}
	return outptr;
}

gameData readGameData(char *gamePath) {
	gameData metaData;
	char lineOfCode[256];
	FILE *f = fopen(gamePath, "r");
	while (1) {
		fgets(lineOfCode, 256, f);
		if (lineOfCode[0] != '#') {
			break;
		}
		printf("%s", lineOfCode);
		if (strncmp(lineOfCode, "#name", strlen("#name")) == 0) {
			metaData.name = substrFromIndexToChar(lineOfCode, GAME_N_MAX, 6, '\n');
			printf("%s\n", metaData.name);
		}
	}
	fclose(f);
}

void chooseAGame() {
	//scan user input for game title
	//execute the chosen program
	DIR *d;
	struct dirent *dir;
	d = opendir(GAMES_PATH);
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			// Eliminate . and ..
			if (strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..")) {
				char gamePath[PATH_MAX];
				strcpy(gamePath, GAMES_PATH);
				strcat(gamePath, dir->d_name);
				printf("%s\n", gamePath);
				// Open files
				gameData mGameData = readGameData(gamePath);

			}
		}
		closedir(d);
	}
}
