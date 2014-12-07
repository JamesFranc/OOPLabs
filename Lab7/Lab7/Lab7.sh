#!/bin/bash
set -v
printf \\n\\n
printf \\f
cat -b Lab7.cpp
printf \\n
cat -b Node.h
printf \\n\\n
cat -b Node.cpp
printf \\n
cat -b HashTable.h

printf \\n\\n
cat -b HashTable.cpp

:
g++ Node.cpp HashTable.cpp Lab7.cpp -o prog7
printf \\n\\n

:

prog7

