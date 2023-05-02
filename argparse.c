#include <stdlib.h>

#include "constants.h"

_Noreturn void argerror(char *progname, char *message) {
	fprintf(
		stderr,
		"%s\n"
		"To play the game, use:\n"
		"  > %s\n"
		"For help, use:\n"
		"  > %s help\n",
		message, progname, progname
	);
	exit(1);
}

_Noreturn void help(char *progname) {
	printf(
		"%s version %s\n"
		"Usage:\n"
		"  %s      - play the game\n"
		"  %s help - this help\n",
		NAME, VERSION, progname, progname
	);
	exit(0);
}
