printf \\n\\n\\n

#!/bin/bash 
set -v
printf \\n\\n\\n
printf \\f
cat -b Item.h
:
printf \\n\\n
cat -b Item.cpp
:
printf \\n\\n
cat -b fileHandler.h
printf \\n\\n
cat -b fileHandler.cpp
printf \\n\\n
cat -b p4.cpp
:
g++ fileHandler.cpp Item.cpp  p4.cpp -o p4
:
p4


date
