#ifndef WORMHOLECALC_H
#define WORMHOLECALC_H

#include <limits>
#include "starchart_types.h"

distance constexpr unreachable = std::numeric_limits<distance>::max();

void addWormhole(std::vector<wormhole>& wormholes, index x, index y, distance length);

void addLastWormhole(matrix& input, matrix& deduced);

void deduceDistances(matrix& input, matrix& deduced, index x, index y);

index indexForShortest(std::vector<distance> &row, index rowNr);

void fillMatrix(matrix& m, size_t size);

std::vector<wormhole> calcWormholes(matrix& input);


#endif // WORMHOLECALC_H
