#include <cstdlib>
#include <vector>
#include <matrix.h>

using namespace std;

vector<unsigned int>& paths(unsigned int i, unsigned int j, Matrix<unsigned int>& input)
{
    vector<unsigned int> values;
    return values;
}

unsigned int minimum(vector<unsigned int>& values)
{
    return 0;
}

void calcWormholes(Matrix<unsigned int>& input, vector< vector<unsigned int> >& tupleList)
{
    vector< vector<unsigned int> > wormholes;
    for(vector<unsigned int> tuple : tupleList){
        if(input[tuple[0]][tuple[1]] <= minimum(paths(tuple[0], tuple[1], input)))
        {
            vector<unsigned int> wormhole;
            wormhole.push_back(tuple[0]);
            wormhole.push_back(tuple[1]);
            wormhole.push_back(input[tuple[0]][tuple[1]]);
            wormholes.push_back(wormhole);
        }
    }
}
