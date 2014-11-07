#include <cstdlib>
#include <vector>
#include <cassert>

using namespace std;

typedef vector< vector<int> > matrix;

void addWormhole(vector<tuple>& wormholes, unsigned int x, unsigned int y, int length)
{
    tuple wormhole = make_tuple(x, y, length);
    wormholes.push_back(wormhole);
}

void addLastWormhole(matrix& input, matrix& deduced)
{

}

void deduceDistance(matrix& input, matrix& deduced, unsigned int x, unsigned int y)
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
        deduced.push_back(row);
        for(unsigned int j = 0; j < size; j++)
            deduced[i].push_back(INT_MAX);
    }
}

void calcWormholes(matrix& input)
{
    matrix deduced;
    fillMatrix(deduced, input.size());
    vector<tuple> wormholes;
    for(unsigned int i = 0; i < input.size() - 1; i++){
        unsigned int j = indexForShortest(input[i], i);
        addWormhole(wormholes, i, j, input[i][j]);
        deduced[i][j] = input[i][j];
        deduceDistances(input, deduced, i, j);
    }
}
