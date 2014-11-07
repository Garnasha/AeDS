#include <cstdlib>
#include <vector>
#include <cassert>
#include <tuple>

using namespace std;

typedef signed int distance;
typedef unsigned int index;
typedef vector< vector<signed int> > matrix;
typedef tuple<unsigned int, unsigned int, signed int> wormhole;

void addWormhole(vector<wormhole>& wormholes, unsigned int x, unsigned int y, int length)
{
    wormhole next = make_tuple(x, y, length);
    wormholes.push_back(next);
}

void addLastWormhole(matrix& input, matrix& deduced)
{

}

void deduceDistances(matrix& input, matrix& deduced, unsigned int x, unsigned int y)
{

}

unsigned int indexForShortest(vector<int> row, unsigned int rowNr)
{
    unsigned int min = 0;
    for(unsigned int j = rowNr + 1; j < row.size(); j++){
        if(row[min] > row[j])
            min = j;
    }
    return min;
}

void fillMatrix(matrix& m, unsigned int size)
{
    for(unsigned int i = 0; i < size; i++){
        vector<int> row;
        m.push_back(row);
        for(unsigned int j = 0; j < size; j++)
            m[i].push_back(INT_MAX);
    }
}

void calcWormholes(matrix& input)
{
    matrix deduced;
    fillMatrix(deduced, input.size());
    vector<wormhole> wormholes;
    for(unsigned int i = 0; i < input.size() - 1; i++){
        unsigned int j = indexForShortest(input[i], i);
        addWormhole(wormholes, i, j, input[i][j]);
        deduced[i][j] = input[i][j];
        deduceDistances(input, deduced, i, j);
    }
    addLastWormhole(input, deduced);
}
