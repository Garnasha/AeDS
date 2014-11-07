#include <vector>
#include <tuple>
#include "wormholeCalc.h"

using std::vector;
using std::tuple;
using std::make_tuple;

void addWormhole(vector<wormhole>& wormholes, index x, index y, distance length)
{
    wormhole next = make_tuple(x, y, length);
    wormholes.push_back(next);
}

void addLastWormhole(matrix& input, matrix& deduced, vector<wormhole>& wormholes)
{
    index x = 0, y = 0;
    distance length = 0;
    for(index i = 0; i < input.size() - 1; i++){
        for(index j = i + 1; j < input[i].size(); j++){
            if(input[i][j] < deduced[i][j] && input[i][j] < input[x][y]){
                x = i;
                y = j;
                length = input[x][y];
            }
        }
    }
    addWormhole(wormholes, x, y, length);
}

void deduceDistances(matrix& deduced, index x, index y)
{
    for(index i = 0; i < deduced[x].size(); i++){
        if(deduced[x][i] != unreachable && deduced[y][i] > deduced[x][y] + deduced[x][i]){
            deduced[y][i] = deduced[x][y] + deduced[x][i];
            deduced[i][y] = deduced[y][i];
        }
    }
    for(index i = 0; i < deduced[y].size(); i++){
        if(deduced[y][i] != unreachable && deduced[x][i] > deduced[x][y] + deduced[y][i]){
            deduced[x][i] = deduced[x][y] + deduced[y][i];
            deduced[i][x] = deduced[x][i];
        }
    }
}

index indexForShortest(vector<distance>& row, index rowNr)
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
            m[i].push_back(unreachable);
    }
}

vector<wormhole> calcWormholes(matrix& input)
{
    matrix deduced;
    fillMatrix(deduced, input.size());
    vector<wormhole> wormholes;
    for(index i = 0; i < input.size() - 1; i++){
        index j = indexForShortest(input[i], i);
        addWormhole(wormholes, i, j, input[i][j]);
        deduced[i][j] = input[i][j];
        deduced[j][i] = input[i][j];
        deduceDistances(deduced, i, j);
    }
    addLastWormhole(input, deduced, wormholes);
    return wormholes;
}
