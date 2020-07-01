#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

enum {PRIME, NOT_PRIME} prime;

void print_array(int *, int, int, int, int);
void sieve(int, int);

int main(int argc, char *argv[])
{
  int ncol = atoi(argv[1]);
  int n = atoi(argv[2]);
  sieve(n, ncol);
  return 0;
}

void print_array(int *a, int x, int y, int n, int ncol)
{
  static int frame = 0;
  FILE *f;
  char filename[100];
  sprintf(filename, "frames/frame%03d.txt", frame++);
  f = fopen(filename, "w");
  fprintf(f, "% 4d * % 4d = % 4d\n", x, y, x*y);
  for (int i=2; i <= n; i++) {
    if (a[i-2] == PRIME)
      fprintf(f, "% 4d", i);
    else
      fprintf(f, "%s", i == x*y ? " del" : "   .");
    if ((i - 1) % ncol == 0 || i == n)
      fprintf(f, "\n");
  }
  fclose(f);
}

void sieve(int n, int ncol)
{
  if (n < 2)
    return;

  int *a = calloc(n - 1, sizeof(int));

  for (int i=2, stop = ceil(sqrt(n)); i <= stop; i++) {
    if (a[i-2] == NOT_PRIME)
      continue;
    for (int j=i, p=0; ; j++) {
      if ((p = i*j) <= n) {
        a[p - 2] = NOT_PRIME;
        print_array(a, i, j, n, ncol);
      } else {
        break;
      }
    }
  }
}
