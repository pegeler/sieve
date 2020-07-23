CXX = gcc -O2

.PHONY: all

all: sieve sieve2

sieve: sieve.c
	$(CXX) $< -o $@ -lm

primes.o: primes.c primes.h
	$(CXX) $< -o $@ -c

sieve2: main.c primes.o
	$(CXX) $^ -o $@ -lm

test:
	python3 check.py 101
