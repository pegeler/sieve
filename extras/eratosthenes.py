#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Sieve of Eratosthenes
"""
from math import floor, sqrt


def sieve(n):
    """Sieve of Eratosthenes"""
    if n < 2:
        return []

    a = [True] * (n-1)
    i = 2
    stop = floor(sqrt(n))

    while i <= stop:
        if not a[i-2]:
            i += 1
            continue
        p = i * i
        while p <= n:
            a[p - 2] = False
            p += i
        i += 1

    return [x for x, y in enumerate(a, 2) if y]


if False:
    from sympy import primerange
    for i in range(10000):
        try:
            assert(set(sieve(i)) == set(primerange(2, i+1)))
        except AssertionError:
            print('{} did not match'.format(i))
            break

if __name__ == "__main__":
    import sys
    print(*sieve(int(sys.argv[1])), sep='\n')
