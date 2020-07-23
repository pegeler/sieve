#include <Rcpp.h>
#include <cmath>

// [[Rcpp::export]]
Rcpp::IntegerVector sieve(int n) {
  if (n < 2)
    return Rcpp::IntegerVector::create(NA_INTEGER);

  Rcpp::LogicalVector a((n + 1) / 2, TRUE);
  for (int i=3, stop=sqrt(n); i <= stop; i+=2)
    if (a[(i-1)>>1] == TRUE)
      for (int p=i*i, inc=i<<1; p <= n; p+=inc)
        a[(p-1)>>1] = FALSE;

  Rcpp::IntegerVector out = Rcpp::IntegerVector::create(2);
  for (int i=1; i < a.size(); i++)
    if (a[i] == TRUE)
      out.push_back((i<<1) + 1);

  return out;
}

/*** R
reference <- c(2L, 3L, 5L, 7L, 11L, 13L, 17L, 19L, 23L, 29L, 31L, 37L, 41L)
message(if (identical(sieve(42), reference)) "OK" else "Not OK")
*/
