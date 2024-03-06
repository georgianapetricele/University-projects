#!/bin/bash
echo 0 > a.txt
# The script on the left is inc.sh
./inc.sh a.txt &
./inc.sh a.txt &
./inc.sh a.txt &
