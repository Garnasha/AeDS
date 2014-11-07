#ifndef WORMHOLECALC_H
#define WORMHOLECALC_H

#include <vector>
#include <tuple>
#include <limits>

typedef signed int distance;
typedef unsigned int index;
typedef vector< vector<signed int> > matrix;
typedef tuple<unsigned int, unsigned int, signed int> wormhole;

distance constexpr unreachable = std::numeric_limits<distance>::max();

void addWormhole(vector<wormhole>& wormholes, unsigned int x, unsigned int y, int length);

void addLastWormhole(matrix& input, matrix& deduced);

void deduceDistances(matrix& input, matrix& deduced, unsigned int x, unsigned int y);

unsigned int indexForShortest(vector<int> row, unsigned int rowNr);

void fillMatrix(matrix& m, unsigned int size);

void calcWormholes(matrix& input);


#endif // WORMHOLECALC_H
