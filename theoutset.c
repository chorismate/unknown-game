#include "delays.h"
#include "randomization.h"

void theoutset(void) {
	dfputs("Stage 1 - The Outset\n", stdout, DFPUTS_SLOW);
	
	const char *TEMPS[] = {
		"freezing", "frigid", "cold", "chilly",
		"mild",     "warm",   "hot",  "scorching"
	};
	const double TEMPTHRESHOLDS = {
		-40.0, 20.0, 
	};
	const double TEMPMIN = 0.0, TEMPMAX = 5.0, TEMPDEC = 0.15, TEMPDECVAR = 0.2;
	double roomtemp = 0.0;
	
	const char *FIRESTATES[] = {
		"dying",   "smoldering", "flickering",
		"burning", "blazing",    "roaring"
	};
	const double FIRETHRESHOLDS[] = {
		0.0,  1.0,  4.0,
		9.0, 16.0, 25.0
	};
	const double FIREMIN = 0.0,
	             FIREDECFACTOR = 0.9, FIREDECCONST = 1.0, FIREDECVAR = 0.2;
	double firestate = 1.5;
	
	const double TEMPCHANGES[] = {
		0.0,  // dead
		0.03, // dying
		0.09, // flickering
		0.18, // burning
		0.3,  // roaring
		0.3   // max
	};
	
	while(1) {
		{
			
		}
		fputs("\033[2J\033[1;1H", stdout);
		dfputs("The room is ",                stdout, DFPUTS_FAST);
		dfputs(TEMPS[(size_t)roomtemp],       stdout, DFPUTS_FAST);
		dfputs(".\nThe fire is ",             stdout, DFPUTS_FAST);
		dfputs(FIRESTATES[(size_t)firestate], stdout, DFPUTS_FAST);
		dfputs(".\n\n",                       stdout, DFPUTS_FAST);
		fputs(">>> ", stdout);
		
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
				"double firestate = %lf\n",
				roomtemp, firestate
			);
			mssleep(2500);
			continue;
		}
		else if(!strcmp(buf, "stoke\n")) {
			dfputs("\nYou stoke the fire.\n", stdout, DFPUTS_FAST);
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
		
		roomtemp  -= variability(TEMPDEC, TEMPDECVAR);
		if(roomtemp < TEMPMIN) roomtemp = TEMPMIN;
		roomtemp  += TEMPCHANGES[(size_t)firestate];
		if(roomtemp > TEMPMAX) roomtemp = TEMPMAX;
		
		firestate -= variability(FIREDEC, FIREDECVAR);
		if(firestate < FIREMIN) firestate = FIREMIN;
		
		if(firestate == FIREMIN) {
			fputs("\033[2J\033[1;1H", stdout);
			dfputs("The fire is completely dead.\n", stdout, DFPUTS_MED);
			fputs("\033[2J\033[1;1H", stdout);
			dfputs("GAME OVER.\n", stdout, DFPUTS_SLOW);
			exit(0);
		}
	}
}