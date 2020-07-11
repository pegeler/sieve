#!/usr/bin/env python3
"""
Euler's Sieve

Copyright 2020 Paul Egeler

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
"""
from math import sqrt, ceil


def sieve(n):
    """Euler's Sieve"""
    if n == 1:
        return []

    primes = {2}.union(set(range(3, n + 1, 2)))

    for i in range(3, ceil(sqrt(n)), 2):
        if i not in primes:
            continue

        not_primes = set()

        for j in primes:
            if j < i:
              continue
            elif i*j <= n:
              not_primes.add(i*j)

        primes -= not_primes

    return sorted(primes)


if False:
    try:
        from sympy import primerange
        assert(set(sieve(10000)) == set(primerange(2, 10000 + 1)))
    except ImportError:
        pass


if __name__ == "__main__":
    import sys
    print(*sieve(int(sys.argv[1])), sep='\n')
