printf \\n\\n\\n

#!/bin/bash 
set -v
printf \\n\\n
printf \\f
cat -b Record.h
printf \\n
cat -b Record.cpp
printf \\n\\n
cat -b Item.h
printf \\n
cat -b Item.cpp

printf \\n\\n
cat -b CreateIndex.h
printf \\n
cat -b CreateIndex.cpp

printf \\n\\n
cat -b SearchIndex.h
printf \\n
cat -b SearchIndex.cpp

printf \\n\\n
cat -b Lab5.cpp
:
g++ Record.cpp Item.cpp CreateIndex.cpp SearchIndex.cpp Lab5.cpp -o search
:
search 12345 prog5.idx


date
