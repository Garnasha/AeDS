#include "wormholeCalc.h"

using std::vector;
using std::tuple;
using std::make_tuple;

void addWormhole(vector<wormhole>& wormholes, index x, index y, distance length)
{
    wormhole next = make_tuple(x, y, length);
    wormholes.push_back(next);
}

void addLastWormhole(matrix const &input, matrix &deduced, vector<wormhole> &wormholes)
{
    index x = 0, y = 0;
    distance length = 0;
    for(index i = 0; i < input.size() - 1; i++){
        for(index j = i + 1; j < input[i].size(); j++){
            if(input[i][j] < deduced[i][j] && (input[i][j] < input[x][y] || (x == y))){
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
        if(deduced[x][i] != unreachable && deduced[y][i] > deduced[x][y] + deduced[x][i] && i != x){
            deduced[y][i] = deduced[x][y] + deduced[x][i];
            deduced[i][y] = deduced[y][i];
        }
    }
    for(index i = 0; i < deduced[y].size(); i++){
        if(deduced[y][i] != unreachable && deduced[x][i] > deduced[x][y] + deduced[y][i] && i != y){
            deduced[x][i] = deduced[x][y] + deduced[y][i];
            deduced[i][x] = deduced[x][i];
        }
    }
}

index indexForShortest(matrix& deduced, vector<distance> const &row, index rowNr)
{
    index min = rowNr;
    for(index j = 0; j < row.size(); j++){
        if(((row[min] > row[j] && j != rowNr) || min == rowNr) && deduced[rowNr][j] == unreachable)
            min = j;
    }
    return min;
}

void fillMatrix(matrix& m, unsigned int size)
{
    for(index i = 0; i < size; i++){
        vector<int> row;
        m.push_back(row);
		for(index j = 0; j < size; j++){
			if(i == j){
				m[i].push_back(0);
			}
			else{
				m[i].push_back(unreachable);
			}
		}
    }
}

vector<wormhole> calcWormholes(const matrix &input)
{
    matrix deduced;
    fillMatrix(deduced, input.size());
    vector<wormhole> wormholes;
    for(index i = 0; i < input.size() - 1; i++){
        index j = indexForShortest(deduced, input[i], i);
        addWormhole(wormholes, i, j, input[i][j]);
        deduced[i][j] = input[i][j];
        deduced[j][i] = input[i][j];
        deduceDistances(deduced, i, j);
    }
    addLastWormhole(input, deduced, wormholes);
    return wormholes;
}
