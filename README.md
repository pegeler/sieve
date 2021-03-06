Sieve of Eratosthenes
=====================

Find all prime numbers between 2 and _n_.

![demo](animate/demo.gif)

## Usage

```
sieve [-c NCOL] [-h] N

Generate prime numbers using the Sieve of Eratosthenes.

positional arguments:
  N           Return primes from 2 to N.

optional arguments:
  -c NCOL     Print primes in 2d table, NCOL columns wide.
              Non-prime natural numbers will be represented by a '.' character.
  -h          Display this help message and exit.
```

## Algorithm

The gist of the algorithm is as follows.

1. List all integers from 2 to _n_.
1. Cross out all multiples of 2 greater than 2.
1. Let _i_ be the next number not already crossed out. Cross out all multiples of  _i_.
1. Repeat previous step while _i_ &le; &Sqrt;_n_.
1. Collect the remaining uncrossed-out numbers. They are prime.

The code doesn't strictly follow this since there are some well-known tweaks to
squeeze a little extra time and space efficiency.

- Instead of crossing out all multiples of _i_, we only check all _i_
  &times; _j_ where _j_ &notin; 2&naturals;, _j_ &ge; _i_, _i_ &times; _j_ &le; _n_.
- We start the algorithm at 3 instead of 2 and thereby allocate half the space
  in our initial list as well as skip step 2 in the original algorithm.
- We use addition and bit operations instead of multiply/divide/modulus. The
  compiler will do the bit ops optimizations on its own if we set the `-O2` flag,
  but it's still fun to do ourselves as an exercise! &#x1F604; <!-- laughing emoji -->

### Reference

Goodaire EG, Parmenter, MM.
**Discrete Mathematics with Graph Theory**, 3rd Ed.
ISBN&nbsp;0&#8209;13&#8209;167995&#8209;3.
p. 116.
