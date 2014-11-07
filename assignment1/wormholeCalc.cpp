#include <cstdlib>
#include <vector>
#include <cassert>

using namespace std;

typedef vector< vector<unsigned int> > matrix;

unsigned int get_by_coords(matrix& m, vector<unsigned int> tuple){
	return m[tuple[0]][tuple[1]];
}

void deduce(matrix& deduced, matrix& input, vector<unsigned int> tuple, vector< vector<unsigned int> >& wormholes)
{
    assert(deduced.size() == input.size() && deduced[0].size() == input[0].size());
    
    if(get_by_coords(deduced, tuple) != get_by_coords(input, tuple)){
        deduced[tuple[0]][tuple[1]] = get_by_coords(input, tuple);
        deduced[tuple[1]][tuple[0]] = get_by_coords(input, tuple);
        for(int i = 0; i < deduced[tuple[0]].size(); i++){
            if(deduced[tuple[0]][i] != INT_MAX && deduced[tuple[1]][i] == INT_MAX){
                deduced[tuple[1]][i] = deduced[tuple[0]][i] + get_by_coords(deduced, tuple);
                deduced[i][tuple[1]] = deduced[tuple[1]][i];
            }
        }
        for(int i = 0; i < deduced[tuple[1]].size(); i++){
            if(deduced[tuple[1]][i] != INT_MAX && deduced[tuple[0]][i] == INT_MAX){
                deduced[tuple[0]][i] = deduced[tuple[1]][i] + get_by_coords(deduced, tuple);
                deduced[i][tuple[0]] = deduced[tuple[0]][i];
            }
        }
        vector<unsigned int> wormhole;
		wormhole.push_back(tuple[0]);
		wormhole.push_back(tuple[1]);
        wormhole.push_back(get_by_coords(input, tuple));
        wormholes.push_back(wormhole);
    }
}

vector< vector<unsigned int> > calcWormholes(matrix& input, vector< vector<unsigned int> >& tupleList)
{
    matrix deduced;
    for(int i = 0; i < input.size(); i++){
        vector<unsigned int> v;
        deduced.push_back(v);
        for(int j = 0; j < input[i].size(); j++){
            deduced[i].push_back(INT_MAX);
        }
    }
    vector< vector<unsigned int> > wormholes;
    vector< vector<unsigned int> > dummyList;
    for(vector<unsigned int> tuple: tupleList){
        deduce(deduced, input, tuple, wormholes);
        if(!(wormholes.back()[0] == tuple[0] && wormholes.back()[1] == tuple[1]))
            dummyList.push_back(tuple);
    }
    if(wormholes.size() < input.size()){
        vector<unsigned int> wormhole;
        wormhole.push_back(dummyList[0][0]);
        wormhole.push_back(dummyList[0][1]);
        wormhole.push_back(get_by_coords(input, dummyList[0]) + 1);
        wormholes.push_back(wormhole);
    }
    return wormholes;
}
