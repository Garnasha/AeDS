#include <cstdlib>
#include <vector>
#include <cassert>

using namespace std;

typedef vector< vector<unsigned int> > matrix;

unsigned int get_by_coords(matrix& m, vector<unsigned int> tuple){
	return m[tuple[0]][tuple[1]];
}

void addWormhole(int x, int y, int length)
{

}

void addLastWormhole(matrix& input, matrix& deduced)
{

}

unsigned int getShortest(vector<unsigned int> row)
{
    return 0;
}

void calcWormholes(matrix& input)
{
    matrix deduced;
    for(int i = 0; i < input.size(); i++){
        vector<unsigned int> row;
        deduced.push_back(row);
        for(int j = 0; j < input[i].size(); j++)
            deduced[i].push_back(INT_MAX);
    }
    for(int i = 0; i < input.size(); i++){

    }
}
