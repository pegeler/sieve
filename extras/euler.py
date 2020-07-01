#!/usr/bin/env python3
"""
Euler's Sieve
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
