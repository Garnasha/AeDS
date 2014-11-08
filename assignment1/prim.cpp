#include "prim.h"

using std::vector;
using std::get;
using std::make_tuple;

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
		wormholes[i] = next_wormhole(metadata);
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
					   meta.mindex, //to
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
	return;
}


void update_inferred(const wormhole &added, matrix &inferred)
{
	//reminder:
	index from = get<0>(added); // is a star already in the MST.
	index to = get<1>(added); // is the star to be added.
	distance dist = get<2>(added); // is the length of the wormhole between the two.
	for(index i = 0; i < inferred.size(); ++i){
		if(inferred[from][i] != unreachable){
			inferred[to][i]
					= inferred[i][to]
					= inferred[from][i] + dist;
		}
	}
	inferred[to][to] = 0; //was set to inferred[from][to]+dist in loop.
}


std::vector<wormhole> solve_starchart(const matrix &input)
{
	auto primresult = prim_MST_enhanced(input);
	find_last_wormhole(input,primresult.second,primresult.first);
	return primresult.first;
}

//and finding the last wormhole requires comparing half the input matrix
//to the matrix of inferred distances, which was constructed just for this...
void find_last_wormhole(const matrix &input,
						const matrix &inferred,
						vector<wormhole> wormholes)
{
	distance min = unreachable;
	index minY = 0, minX = 0;
	for(index i = 0; i < input.size(); ++i){
		for(index j = i + 1; j < input.size(); ++j){
			if(input[i][j] < inferred[i][j] && input[i][j] < min){
				min = input[i][j];
				minY = i;
				minX = j;
			}
		}
	}
	//now there's an edge case, the catching of which is a bit ugly
	//but still in at most 2 N searches of complexity N, so total O(N^2)
	if(minY == 0 && minX == 0){ //no mismatch found: inferred already correct.
		for(index i = 0; i < input.size(); ++i){
			for(index j = i + 1; j < input.size(); ++j){
				if(std::find(wormholes.begin(),wormholes.end(),
							 make_tuple(i,j,input[i][j])) == wormholes.end() &&
				   std::find(wormholes.begin(),wormholes.end(),
							 make_tuple(j,i,input[j][i])) == wormholes.end()){
					//we've found two stars without a connecting wormhole
					min = input[i][j];
					minY = i;
					minX = j;
					//and since the Nth wormhole is irrelevant in this case,
					//we pick this first suitable pair of stars to connect.
				}
			}
		}
	}
	//end edge case.
	wormholes[wormholes.size() - 1] = make_tuple(minY,minX,min);
	return;
}
