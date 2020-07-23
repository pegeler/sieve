#include "primes.h"

/* is_prime: test primality of a number */
int is_prime(uint32 n) {
  if (n <= 3)
    return n > 1;

  if ((n & 1) == 0 || n % 3 == 0)
    return 0;

  for (uint32 i = 5; i*i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return 0;

  return 1;
}

/* next_prime: find the next prime number */
uint32 next_prime(uint32 n) {
  while (!is_prime(++n))
    ;
  return n;
}

/* print_PrimeList: if ncol < 2, prints the primes, one number per line;
 * if ncol >= 2, prints a table with ncol numbers per line and all
 * natural numbers not present in array are represented by a '.' char.
 */
void print_PrimeList(PrimeList *pl, int ncol)
{
  if (ncol < 2) {
    for (int i=0; i < pl->size; i++)
      printf("%d\n", pl->a[i]);
  } else {
    int pad = 1;
    for (int m = pl->n; m > 0; pad++)
      m /= 10;
    for (int i=2; i <= pl->n; i++) {
      if (*(pl->a) == i)
        printf("% *d", pad, *(pl->a++));
      else
        printf("%*s", pad, ".");
      if ((i-1) % ncol == 0 || i == pl->n)
        putchar('\n');
    }
  }
}

static enum {PRIME, NOT_PRIME} prime;

/* sieve: perform the sieve of Eratosthenes */
PrimeList sieve(uint32 n)
{
  uint32 len = (n+1)/2;
  PrimeList pl;
  pl.n = n;
  pl.a = calloc(len, sizeof(uint32));

  /* If we fail to allocate memory or if there are no primes to calculate,
   * we will just exit early
   */
  if (pl.a == NULL || n < 2)
    return pl;

  for (uint32 i=3, stop=sqrt(n); i <= stop; i+=2)
    if (pl.a[(i-1)>>1] == PRIME)
      for (uint32 p=i*i, inc=i<<1; p <= n; p+=inc)
        pl.a[(p-1)>>1] = NOT_PRIME;

  uint32 j=1;
  for (uint32 i=1; i < len; i++)
    if (pl.a[i] == PRIME)
      pl.a[j++] = (i<<1) + 1;

  pl.a[0] = 2;
  pl.a = realloc(pl.a, j*sizeof(uint32));
  pl.size = j;

  return pl;
}
