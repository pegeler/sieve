/*
 * Sieve of Eratosthenes
 *
 * Copyright 2020 Paul Egeler
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <Rcpp.h>
#include <vector>
#include <cmath>

// [[Rcpp::export]]
Rcpp::IntegerVector sieve(int n) {
  if (n < 2)
    return Rcpp::IntegerVector::create(NA_INTEGER);

  std::vector< bool > a((n+1)/2-1, true);
  for (int i=3, stop=sqrt(n); i <= stop; i+=2)
    if (a[(i-3)>>1] == true)
      for (int p=i*i, inc=i<<1; p <= n; p+=inc)
        a[(p-3)>>1] = false;

  std::vector< int > out = {2};
  for (int i=0; i < a.size(); i++)
    if (a[i] == true)
      out.push_back((i<<1) + 3);

  return Rcpp::wrap(out);
}

/*** R
reference <- c(2L, 3L, 5L, 7L, 11L, 13L, 17L, 19L, 23L, 29L, 31L, 37L, 41L)
message(if (identical(sieve(42), reference)) "OK" else "Not OK")
*/
