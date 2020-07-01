/*
  FILE: sieve.c
  PURPOSE: Generate all prime numbers between 2:n using the Sieve of Eratosthenes
  DATE: 2020-06-20
  AUTHOR: Paul Egeler, MS, GStat
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void usage(char *);
int stoi(char *);
void print_primes(int *);
void print_array(int *, int, int);
int *sieve(int);

int main(int argc, char *argv[])
{
  int *a;
  int n;
  int c;
  int cflag = 0;
  int ncol;

  while ((c = getopt(argc, argv, "c:")) != -1)
    switch(c) {
      case 'c':
        cflag = 1;
        ncol = stoi(optarg);
        break;
      case '?':
      default:
        usage(argv[0]);
        break;
    }

  if (optind != argc - 1)
    usage(argv[0]);

  n = stoi(argv[optind]);
  a = sieve(n);

  if (a != NULL)
    if (cflag)
      print_array(a, n, ncol);
    else
      print_primes(a);

  return 0;
}


void usage(char *prog)
{
  char *s = strrchr(prog, '/');
  fprintf(
    stderr,
    "Sieve of Eratosthenes\n"
    "  usage: %s [-c ncol] n\n",
    s != NULL ? ++s : prog
  );
  exit(1);
}

int stoi(char *s)
{
  int n = 0;
  char c;
  while ((c = *(s++)) >= '0' && c <= '9')
    n = n * 10 + (c - '0');
  return n;
}

void print_primes(int *a)
{
  while (*a != 0)
    printf("%d\n", *(a++));
}

void print_array(int *a, int n, int ncol)
{
  int pad = 1;
  for (int m = n; m > 0; pad++)
    m /= 10;
  for (int i=2; i <= n; i++) {
    if (*a == i)
      printf("% *d", pad, *(a++));
    else
      printf("%*s", pad, ".");
    if ((i-1) % ncol == 0 || i == n)
      putchar('\n');
  }
}

int *sieve(int n)
{
  if (n < 2)
    return NULL;

  int *a = calloc(n - 1, sizeof(int));
  enum {PRIME, NOT_PRIME} prime;

  for (int i=2, stop=sqrt(n); i <= stop; i++) {
    if (a[i-2] == NOT_PRIME)
      continue;
    for (int p=i*i; p <= n; p+=i)
      a[p-2] = NOT_PRIME;
  }

  int j=0;
  for (int i=0; i < n-1; i++)
    if (a[i] == PRIME)
      a[j++] = i + 2;

  a[j] = 0;
  a = realloc(a, (j+1) * sizeof(int));

  return a;
}
