This folder should contain everything necessary to compile our solution to
exercise 2 of A&DS. Do note that it is written for C++11. Assuming you're
using a recent version of gcc/g++ on Linux, the following should compile
everything properly:
g++ -std=c++11 *.cpp

Since I tried to make this code somewhat compiler-friendly (at least, I'd 
expect an optimizing compiler to appreciate const correctness, and the use of 
standard library templates which are likely themselves written for being both
optimized and amenable to further compiler optimization), I'd also be really 
interested in seeing how it compares to the other (C/C++) solutions
when both solution are compiled optimizing like this:
g++ -std=c++11 -march=native -O3 *.cpp
