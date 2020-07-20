Sieve of Eratosthenes
=====================

Find all prime numbers between 2 and _n_.

![demo](animate/demo.gif)

## Algorithm

1. List all integers from 2 to _n_.
1. Cross out all multiples of 2 greater than 2.
1. Let _i_ be the next number not already crossed out. Cross out all _i_ &times; _j_ where _i_ &le; _j_ and _i_ &times; _j_ &le; _n_.
1. Repeat previous step while _i_ &le; &Sqrt;_n_.

The remaining uncrossed-out numbers are prime.

### Reference

Goodaire EG, Parmenter, MM.
**Discrete Mathematics with Graph Theory**, 3rd Ed.
ISBN&nbsp;0&#8209;13&#8209;167995&#8209;3.
p. 116.
