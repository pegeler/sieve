/*****************************************************************************
*  FILE: main.c
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
#include <string.h>
#include <unistd.h>
#include "primes.h"

void usage(char *);
int stoi(char *);

int main(int argc, char *argv[])
{
  PrimeList pl;
  int n;
  int c;
  int ncol = 0;

  while ((c = getopt(argc, argv, "c:h")) != -1)
    switch(c) {
      case 'c':
        ncol = stoi(optarg);
        break;
      case 'h':
        /* FALL THRU */
      case '?':
        usage(argv[0]);
    }

  if (optind != argc - 1) {
    fprintf(stderr, "%s: missing argument -- must supply 'N'\n", argv[0]);
    usage(argv[0]);
  }

  n = stoi(argv[optind]);
  pl = sieve(n);

  print_PrimeList(&pl, ncol);

  return 0;
}

/* usage: program usage and options */
void usage(char *prog)
{
  char *s = strrchr(prog, '/');
  fprintf(
    stderr,
    "usage:\n%s [-c NCOL] [-h] N\n\n"
    "Generate prime numbers using the Sieve of Eratosthenes.\n\n"
    "positional arguments:\n"
    "  N           Return primes from 2 to N.\n\n"
    "optional arguments:\n"
    "  -c NCOL     Print primes in 2d table, NCOL columns wide.\n"
    "              Non-prime natural numbers will be represented by a '.' character.\n"
    "  -h          Display this help message and exit.\n",
    s != NULL ? ++s : prog
  );
  exit(1);
}

/* stoi: user-defined version of atoi(3);
 * returns zero for bad input and negative numbers
 */
int stoi(char *s)
{
  int n = 0;
  char c;
  while ((c = *(s++)) >= '0' && c <= '9')
    n = n * 10 + (c - '0');
  return n;
}
