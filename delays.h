#ifndef __DELAYS_H__
#define __DELAYS_H__

const uint64_t DPFUTS_SLOW = 100
const uint64_t DFPUTS_MED  =  50
const uint64_t DFPUTS_FAST =  25

int mssleep(uint64_t ms);
int dfputs(const char *restrict s, FILE *restrict stream, uint64_t ms);

#endif