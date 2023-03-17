#ifndef __DELAYS_H__
#define __DELAYS_H__

int mssleep(uint64_t ms);
int dfputs(const char *restrict s, FILE *restrict stream, uint64_t ms);

#endif