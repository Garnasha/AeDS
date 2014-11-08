#include "prim.h"

using std::vector;

matrix gen_blank_inferred(size_t N)
{
	return vector<vector<distance>>(N,vector<distance>(N,unreachable));
}


std::pair<std::vector<wormhole>, matrix> prim_MST_enhanced(const matrix &input)
{
	prim_minimals metadata = prim_init(input);
	vector<wormhole> wormholes(input.size());
	matrix inferred = gen_blank_inferred(input.size());
	fill_diagonal(inferred,0);
	for(index i = 0; i < input.size() - 1; ++i){ //prim can find N-1 wormholes
		wormholes[i] = next_wormhole(metadata,input);
		update_inferred(wormholes[i],inferred);
		update_minimals(metadata,input);
	}
	return make_pair(wormholes,inferred);
}

/*!
 * \brief prim_init constructs the initial enhanced vector<distance> used by
 * prim's algorithm.
 * \param input the original adjacency matrix
 * \return a prim_minimals with state corresponding to the nascent MST
 * containing just the startnode (hardcoded as node 0 (w.l.o.g.)).
 */
prim_minimals prim_init(matrix const &input){
	index constexpr startnode = 0;
	prim_minimals starter; //default constructor is fine;
	distance minimal_distance = unreachable; /* can't use starter.minimals yet
		since it's still being initialised.*/
	for(index i = 0; i < input.size(); ++i){
		starter.minimals.push_back(
				prim_minimals::minpoint{false,startnode,input[startnode][i]});
		if(i != startnode && input[startnode][i] < minimal_distance){
			minimal_distance = input[startnode][i];
			starter.mindex = i;
		}
	}
	starter.minimals[startnode].included = true;
	return starter;
}

void fill_diagonal(matrix M, distance n)
{
	for(index i = 0; i < M.size(); ++i){
		M[i][i] = n;
	}
}


wormhole next_wormhole(const prim_minimals &meta)
{
	 return make_tuple(meta.minimals[meta.mindex].nearest, //from
					   mindex, //to
					   meta.minimals[meta.mindex].dist); //distance
}


void update_minimals(prim_minimals &meta, const matrix &input)
{
	index added = meta.mindex;
	distance minimal = unreachable;
	meta.minimals[added].included = true;
	for (index i = 0; i < input.size(); ++i){
		if(input[added][i] < meta.minimals[i].dist){
			meta.minimals[i].dist = input[added][i];
			meta.minimals[i].nearest = added;
		}
		if(!meta.minimals[i].included && meta.minimals[i].dist < minimal){
			minimal = meta.minimals[i].dist;
			meta.mindex = i;
		}
	}

}


void update_inferred(const wormhole &added, matrix &inferred)
{

}


std::vector<wormhole> solve_starchart(const matrix &input)
{

}


wormhole find_last_wormhole(const matrix &input, const matrix &inferred)
{

}
