#include "constants.h"
#include "delays.h"
#include "randomization.h"

// TODO
// add actions enum so as to allow addition of new actions

void theoutset(void) {
	dfputs("Stage 1 - The Outset\n", stdout, DFPUTS_SLOW);
	
	// Define constants and related variables
	
	// Temperatures in Celsius, which is more or less arbitrary
	const char *TEMPS[] = {
		"freezing",
		"frigid", "cold", "chilly",
		"mild",   "warm", "hot",  "scorching"
	};
	const double TEMPTHRESHOLDS = {
		0.0,   5.56,  11.67,
		18.33, 23.89, 26.67, 32.22
	};
	const size_t AMTOFTEMPS = 8;
	const double
		TEMPMIN = 0.0, TEMPMAX = 5.0,
		TEMPDEC = 0.15, TEMPDECVAR = 0.2;
	double roomtemp = 21.0;
	
	// Fire states
	const char *FIRESTATES[] = {
		"dead",
		"dying",   "smoldering", "flickering",
		"burning", "blazing",    "roaring"
	};
	const double FIRETHRESHOLDS[] = {
		0.0,  1.0,  4.0,
		9.0, 16.0, 25.0
	};
	const size_t AMTOFSTATES = 7;
	const double
		FIREMIN = 0.0, FIREDECFACTOR = 0.9,
		FIREDECCONST = 1.0, FIREDECVAR = 0.2;
	double firestate = FIREMIN;
	uint64_t matches = 8;
	
	const double TEMPCHANGES[] = {
		0.0,  // dead
		0.03, // dying
		0.09, // flickering
		0.18, // burning
		0.3,  // roaring
		0.3   // max
	};
	
	while(1) {
		fputs(CLEAR, stdout);
		dfputs("The room is ", stdout, DFPUTS_FAST);
		{
			size_t ptr = 0;
			while(TEMPTHRESHOLDS[ptr] < roomtemp) {
				if(ptr == (AMTOFTEMPS-1)) break;
				else                      ptr++;
			}
			/* TODO */
		}
		dfputs(".\nThe fire is ", stdout, DFPUTS_FAST);
		{
			size_t ptr = 0;
			while(/* TODO */) {
				/* TODO */
			}
			/* TODO */
		}
		dfputs(".\n\n", stdout, DFPUTS_FAST);
		fputs(">>> ", stdout);
		
		/* old version
		fputs("\033[2J\033[1;1H", stdout);
		dfputs("The room is ",                stdout, DFPUTS_FAST);
		dfputs(TEMPS[(size_t)roomtemp],       stdout, DFPUTS_FAST);
		dfputs(".\nThe fire is ",             stdout, DFPUTS_FAST);
		dfputs(FIRESTATES[(size_t)firestate], stdout, DFPUTS_FAST);
		dfputs(".\n\n",                       stdout, DFPUTS_FAST);
		fputs(">>> ", stdout);
		*/
		
		char buf[24];
		fgets(buf, 24, stdin);
		if(!strcmp(buf, "help\n")) {
			/* TODO output help */
			sleep(3);
			continue;
		}
		else if(!strcmp(buf, "devinfo\n")) {
			printf(
				"Debug info:\n"
				"double roomtemp  = %lf\n"
				"double firestate = %lf\n"
				"uint64_t matches = %llu\n", // TODO
				// use format specifier for uint64_t instead of unsigned long long
				roomtemp, firestate, matches
			);
			mssleep(2500);
			continue;
		}
		else if(!strcmp(buf, "stoke\n")) {
			dfputs("\nYou stoke the fire.\n", stdout, DFPUTS_FAST);
			// TODO
			//   - add wood amount
			//   - use new arrays here
			firestate += 1.0;
			if(firestate > FIREMAX) firestate = FIREMAX;
			dfputs("The fire is ",                stdout, DFPUTS_FAST);
			dfputs(FIRESTATES[(size_t)firestate], stdout, DFPUTS_FAST);
			dfputs(".\n",                         stdout, DFPUTS_FAST);
			mssleep(3000);
		}
		else if(strcmp(buf, "wait\n")) {
			dfputs(
				"Unrecognized action.\n"
				"If you need help, type \"help\" into the prompt.\n",
				stdout, DFPUTS_MED
			);
		}
		
		// TODO
		// use new method for more memory safety
		roomtemp  -= variability(TEMPDEC, TEMPDECVAR);
		if(roomtemp < TEMPMIN) roomtemp = TEMPMIN;
		roomtemp  += TEMPCHANGES[(size_t)firestate];
		if(roomtemp > TEMPMAX) roomtemp = TEMPMAX;
		
		firestate -= variability(FIREDEC, FIREDECVAR);
		if(firestate < FIREMIN) firestate = FIREMIN;
		
		// TODO
		// allow re-lighting of fire
		if(firestate == FIREMIN) {
			fputs("\033[2J\033[1;1H", stdout);
			dfputs("The fire is completely dead.\n", stdout, DFPUTS_MED);
			fputs("\033[2J\033[1;1H", stdout);
			dfputs("GAME OVER.\n", stdout, DFPUTS_SLOW);
			exit(0);
		}
	}
}