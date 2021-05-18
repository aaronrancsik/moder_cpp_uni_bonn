#!/usr/bin/env bash

rm -rf ./build/
mkdir -p ./build/
clang++ -c -I ./include/ ./src/subtract.cpp -o build/subtract.o
clang++ -c -I ./include/ ./src/sum.cpp -o build/sum.o
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o
clang++ -I ./include -o build/main src/main.cpp build/libipb_arithmetic.a
cp ./build/main ./results/bin
cp ./build/libipb_arithmetic.a ./results/lib/