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

#define GAMES_PATH "./games/"

gameData readGameData(char *gamePath) {
	char lineOfCode[256];
	FILE *f = fopen(gamePath, "r");
	fgets(lineOfCode, 256, f);	
	fclose(f);
	printf("%s", lineOfCode);
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
