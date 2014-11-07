#ifndef WORMHOLECALC_H
#define WORMHOLECALC_H

#include <cstdlib>
#include <vector>
#include <cassert>
#include <tuple>

typedef signed int distance;
typedef unsigned int index;
typedef vector< vector<signed int> > matrix;
typedef tuple<unsigned int, unsigned int, signed int> wormhole;

void addWormhole(vector<wormhole>& wormholes, unsigned int x, unsigned int y, int length);

void addLastWormhole(matrix& input, matrix& deduced);

void deduceDistances(matrix& input, matrix& deduced, unsigned int x, unsigned int y);

unsigned int indexForShortest(vector<int> row, unsigned int rowNr);

void fillMatrix(matrix& m, unsigned int size);

void calcWormholes(matrix& input);


#endif // WORMHOLECALC_H
