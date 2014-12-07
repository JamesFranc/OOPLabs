printf \\n\\n\\n

#!/bin/bash 
set -v
printf \\n\\n
printf \\f
cat -b Lab8Search.cpp
printf \\n

:
g++ Record.cpp Item.cpp Node.cpp HashTable.cpp Lab8Search.cpp -o search
:
search


date
