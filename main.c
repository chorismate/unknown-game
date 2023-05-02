#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "main.h"

#include "argparse.h"
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
	if(argc > 1) argerror(argv[0], "Too many command-line arguments.");
	if(argc == 1) {
		if(!strcmp(argv[1], "help")) help(argv[0]);
		else argerror("Unrecognized command-line argument.");
	}
	fputs("Welcome to Unknown.\n", stdout);
	return 0;
}