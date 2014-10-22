#include <cstdlib>
#include <vector>
#include <matrix.h>
#include <matrix.cpp>

using namespace std;

bool pathExists(unsigned int i, unsigned int j, Matrix<unsigned int>& input, vector< vector<unsigned int> >& wormholes)
{
    if(wormholes.size() <= 1)
        return false;
    vector< vector<unsigned int> > dummy;
    for(vector<unsigned int> wormhole : wormholes)
        dummy.push_back(wormhole);
    unsigned int length = 0;
    for(vector<unsigned int> wormhole : dummy){
        if(wormhole[0] == j){
            j = wormhole[1];
            length += wormhole[2];
        }
        if(wormhole[1] == j){
            j = wormhole[0];
            length += wormhole[2];
        }
        if(wormhole[0] == i){
            i = wormhole[1];
            length += wormhole[2];
        }
        if(wormhole[1] == i){
            i = wormhole[0];
            length += wormhole[2];
        }
        if(j == i && length == input[i][j])
            return true;
    }
    return false;
}

void calcWormholes(Matrix<unsigned int>& input, vector< vector<unsigned int> >& tupleList)
{
    vector< vector<unsigned int> > wormholes;
    for(vector<unsigned int> tuple : tupleList){
        if(!pathExists(tuple[0], tuple[1], input, wormholes))
        {
            vector<unsigned int> wormhole;
            wormhole.push_back(tuple[0]);
            wormhole.push_back(tuple[1]);
            wormhole.push_back(input[tuple[0]][tuple[1]]);
            wormholes.push_back(wormhole);
        }
    }
}
