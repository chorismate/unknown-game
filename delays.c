#include <stdio.h>
#include <time.h>

int mssleep(uint64_t ms) {
	struct timespec rqtp;
	rqtp.tv_nsec = (ms%1000) * 1000000;
	rqtp.tv_sec  =  ms/1000;
	return nanosleep(&rqtp, NULL);
}

int dfputs(const char *restrict s, FILE *restrict stream, uint64_t ms) {
	for(size_t ptr = 0; s[ptr] != '\0'; ptr++) {
		if (fputc(s[ptr], stream) == EOF)
			return EOF;
		fflush(stream);
		mssleep(ms);
	}
	return 1;
}
