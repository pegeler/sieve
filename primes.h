#ifndef PRIMES_H
#define PRIMES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned int uint32;
typedef struct {
  uint32 *a;    /* array of prime numbers */
  uint32 size;  /* size of array */
  uint32 n;     /* originally-specified upper-bound */
} PrimeList;

int is_prime(uint32);
uint32 next_prime(uint32);
void print_PrimeList(PrimeList *, int);
PrimeList sieve(uint32);

#endif
