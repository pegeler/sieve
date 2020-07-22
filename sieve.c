/*****************************************************************************
*  FILE: sieve.c
*  PURPOSE: Generate all prime numbers between 2:n using the Sieve of Eratosthenes
*  DATE: 2020-06-20
*  AUTHOR: Paul Egeler, MS, GStat
*
*  Copyright 2020 Paul Egeler
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*****************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void usage(char *);
int stoi(char *); /* User-defined version of atoi(3) */
void print_list(int *);
void print_array(int *, int, int);
int *sieve(int);

int main(int argc, char *argv[])
{
  int *a;
  int n;
  int c;
  int ncol = 0;

  while ((c = getopt(argc, argv, "c:")) != -1)
    switch(c) {
      case 'c':
        ncol = stoi(optarg);
        break;
      case '?':
        usage(argv[0]);
    }

  if (optind != argc - 1)
    usage(argv[0]);

  n = stoi(argv[optind]);
  a = sieve(n);

  if (a != NULL)
    if (ncol)
      print_array(a, n, ncol);
    else
      print_list(a);

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

void print_list(int *a)
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

  int len = (n+1)/2;
  int *a = calloc(len, sizeof(int));
  enum {PRIME, NOT_PRIME} prime;

  for (int i=3, stop=sqrt(n); i <= stop; i+=2)
    if (a[(i-1)>>1] == PRIME)
      for (int p=i*i, inc=i<<1; p <= n; p+=inc)
        a[(p-1)>>1] = NOT_PRIME;

  int j=1;
  for (int i=1; i < len; i++)
    if (a[i] == PRIME)
      a[j++] = (i<<1) + 1;

  a[0] = 2;
  a[j] = 0;
  a = realloc(a, (j+1) * sizeof(int));

  return a;
}
