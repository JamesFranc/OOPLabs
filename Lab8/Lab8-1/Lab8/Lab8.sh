printf \\n\\n\\n

#!/bin/bash 
set -v
printf \\n\\n
printf \\f
cat -b main.cpp
printf \\n
cat -b Record.h
printf \\n
cat -b Record.cpp
printf \\n
cat -b Item.h
printf \\n
cat -b Item.cpp
printf \\n
cat -b Node.h
printf \\n
cat -b Node.cpp
printf \\n
cat -b HashTable.h
printf \\n
cat -b HashTable.cpp
printf \\n
cat -b CreateIndex.h
printf \\n
cat -b CreateIndex.cpp

printf \\n\\n
:
g++ Record.cpp Item.cpp Node.cpp HashTable.cpp CreateIndex.cpp main.cpp -o p8
:
p8
