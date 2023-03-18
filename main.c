#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "main.h"

#include "delays.h"
#include "theoutset.h"



int main(int argc, char **argv) {
	if(argv[0] == NULL) {
		fputs(
			"argv[0] is NULL\n"
			"faulty exec?\n",
			stderr
		);
		return 1;
	}
	if(argc > 1) {
		fprintf(
			stderr,
			"Too many command-line arguments.\n"
			"To play the game, use\n"
			"  > %s\n"
			"For help, use\n"
			"  > %s help\n",
			argv[0], argv[0]
		);
		return 1;
	}
	if(!strcmp(argv[1], "version")) {
		printf(
			"unknown-game"
		); // TODO
	}
	fputs("Welcome to Unknown.\n", stdout);
	return 0;
}