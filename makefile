CXX = gcc -O2

.PHONY: all

all: sieve

sieve: sieve.c
	$(CXX) $< -o $@ -lm
