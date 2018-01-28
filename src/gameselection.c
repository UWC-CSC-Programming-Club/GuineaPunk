#include "gameselection.h"
#include "game.h"
#include <dirent.h>
#include <stdio.h>

void chooseAGame() {
	//scan user input for game title
	//execute the chosen program
	DIR *d;
	struct dirent *dir;
	d = opendir(".");
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
}
