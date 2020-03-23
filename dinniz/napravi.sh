#!/bin/bash
gcc -c *.c && gcc *.o -O0 -o test && rm -f *.o
