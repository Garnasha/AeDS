#include "prim.h"

using std::vector;

matrix gen_blank_inferred(size_t N)
{
	return vector<vector<distance>>(N,vector<distance>(N,unreachable));
}

prim_minimals prim_init(const matrix& input)
{

}

std::pair<vector<wormhole>, matrix> prim_MST_enhanced(const matrix &input)
{
	prim_minimals metadata = prim_init(input);
	vector<wormhole> wormholes(input.size());
	matrix inferred = gen_blank_inferred(input.size());
	inferred[0][0] = 0;
	for(size_t i = 0; i < input.size(); ++i){
		wormholes[i] = next_wormhole(metadata,input);
		update_inferred(wormholes[i],inferred);
		update_minimals(metadata,input);
	}
	return make_pair(wormholes,inferred);
}
