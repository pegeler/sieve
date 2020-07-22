#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from sympy import primerange
from sys import argv
from subprocess import run, PIPE

cmd = ['python3', argv[1], argv[2]]
proc = run(cmd, check=True, stdout=PIPE)

a = {int(x) for x in proc.stdout.decode('utf-8').strip().split('\n')}
b = set(primerange(2, int(argv[2]) + 1))

if a == b:
    print('OK')
else:
    print('Mismatch!')

