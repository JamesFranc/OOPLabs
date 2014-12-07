printf \\n\\n\\n

#!/bin/bash 
set -v
printf \\n\\n\\n
printf \\f
cat -b p3.h
:
printf \\n\\n
cat -b Bridge.cpp
:
printf \\n\\n
cat -b BridgeTest.cpp
:
g++ Bridge.cpp BridgeTest.cpp -o bridge
:
bridge


date
