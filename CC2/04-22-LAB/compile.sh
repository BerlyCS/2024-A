#/bin/bash

cmake -B build/
cd build/
make

echo "------"
./program

