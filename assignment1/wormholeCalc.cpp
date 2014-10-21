#include <cstdlib>
#include <vector>
#include <matrix.h>

using namespace std;

vector<unsigned int> paths(unsigned int i, unsigned int j, Matrix& input)
{
    return NULL;
}

unsigned int minimum(vector<unsigned int>& values)
{
    return 0;
}

void calcWormholes(Matrix& input, vector< vector<unsigned int> >& tupleList)
{
    vector<unsigned int[3]> wormholes;
    for(vector<unsigned int> tuple : tupleList){
        if(input[tuple[0]][tuple[1]] <= minimum(paths(tuple[0], tuple[1], input)){
                wormholes.push_back({tuple[0], tuple[1], input[tuple[0]][tuple[1]]});
        }
    }
}
