#include <cstdlib>
#include <vector>
#include <matrix.h>
#include <matrix.cpp>

using namespace std;

bool pathExists(unsigned int i, unsigned int j, unsigned int target, vector< vector<unsigned int> >& wormholes, unsigned int length)
{
    if(length > target)
        return false;
    if(length == target && i == j)
        return true;
    if(wormholes.size() == 0)
        return false;
    bool exists1, exists2;
    vector<unsigned int> wormhole = wormholes.back();
    wormholes.pop_back();
    if(i == wormhole[0])
        exists1 = pathExists(wormhole[0], j, target, wormholes, length + wormhole[2]);
    if(i == wormhole[1])
        exists1 = pathExists(wormhole[1], j, target, wormholes, length + wormhole[2]);
    if(j == wormhole[0])
        exists1 = pathExists(i, wormhole[0], target, wormholes, length + wormhole[2]);
    if(j == wormhole[1])
        exists1 = pathExists(i, wormhole[1], target, wormholes, length + wormhole[2]);

    exists2 = pathExists(i, j, target, wormholes, length);
    wormholes.push_back(wormhole);
    return (exists1 || exists2);
}

void calcWormholes(Matrix<unsigned int>& input, vector< vector<unsigned int> >& tupleList)
{
    vector< vector<unsigned int> > wormholes;
    for(vector<unsigned int> tuple : tupleList){
        if(!pathExists(tuple[0], tuple[1], input[tuple[0]][tuple[1]], wormholes, 0))
        {
            vector<unsigned int> wormhole;
            wormhole.push_back(tuple[0]);
            wormhole.push_back(tuple[1]);
            wormhole.push_back(input[tuple[0]][tuple[1]]);
            wormholes.push_back(wormhole);
        }
    }
}
