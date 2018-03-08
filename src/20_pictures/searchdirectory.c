//
// Created by marc on 03/03/18.
//

#include "bomberman.h"

int search_folder(char* dirname, t_control* control) {
	DIR* FD;
	struct dirent* f;

	(void)control;

	if (NULL == (FD = opendir(dirname))) {
		fprintf(stderr, "opendir() impossible\n");
		return (-1);
	}
	my_putstr(dirname);
	while ((f = readdir(FD))) {
		my_putstr(f->d_name);
	}
	closedir(FD);
	return (1);
}
