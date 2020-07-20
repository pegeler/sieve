#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from sympy import primerange
from sys import argv
from subprocess import run, PIPE

cmd = ['./sieve', argv[1]]
proc = run(cmd, check=True, stdout=PIPE)

a = {int(x) for x in proc.stdout.decode('utf-8').strip().split('\n')}
b = set(primerange(2, int(argv[1]) + 1))

if a == b:
    print('OK')
else:
    print('Mismatch!')

