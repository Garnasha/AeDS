#include <cstdlib>
#include <vector>
#include <cassert>
#include <tuple>

using namespace std;

typedef signed int Distance;
typedef unsigned int index;
typedef vector<vector<Distance>> matrix;
typedef tuple<index, index, Distance> wormhole;

void addWormhole(vector<wormhole>& wormholes, index x, index y, Distance length)
{
    wormhole next = make_tuple(x, y, length);
    wormholes.push_back(next);
}

void addLastWormhole(matrix& input, matrix& deduced)
{

}

void deduceDistances(matrix& input, matrix& deduced, index x, index y)
{

}

index indexForShortest(vector<Distance> row, index rowNr)
{
    index min = 0;
    for(index j = rowNr + 1; j < row.size(); j++){
        if(row[min] > row[j])
            min = j;
    }
    return min;
}

void fillMatrix(matrix& m, unsigned int size)
{
    for(index i = 0; i < size; i++){
        vector<int> row;
        m.push_back(row);
        for(index j = 0; j < size; j++)
            m[i].push_back(INT_MAX);
    }
}

void calcWormholes(matrix& input)
{
    matrix deduced;
    fillMatrix(deduced, input.size());
    vector<wormhole> wormholes;
    for(index i = 0; i < input.size() - 1; i++){
        index j = indexForShortest(input[i], i);
        addWormhole(wormholes, i, j, input[i][j]);
        deduced[i][j] = input[i][j];
        deduceDistances(input, deduced, i, j);
    }
    addLastWormhole(input, deduced);
}
