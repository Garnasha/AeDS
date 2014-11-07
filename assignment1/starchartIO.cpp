#include "starchartIO.h"

using std::istream;
using std::ostream;
using std::vector;
using std::tuple;
using std::size_t;
using std::get;

/* note: signed ints are used for distances because time traveling wormholes
 * are an unlikely but extremely easily caught edge case.
 */

matrix read_adjacency_matrix(istream &instream){
	size_t N;
	char dev_null;
	instream >> N;
	std::cout << "Read N as " << N << std::endl;
	matrix adjacencies(N,vector<distance>(N));
	instream >> dev_null;
	std::cout << "Discarding " << dev_null << std::endl;
	for(size_t i = 0; i < N; ++i){
		for(size_t j = 0; j < N; ++j){
			instream >> adjacencies[i][j];
		}
	}
	return adjacencies;
}

void output_wormhole_list(ostream &outstream, vector<wormhole> const links){
	outstream << links.size() << "\n-";
	for(auto t : links){
		outstream << '\n' << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t);
	}
	outstream << std::flush;
}



matrix adjacencies_from_stdin()
{
	return read_adjacency_matrix(std::cin);
}


void wormholes_to_stdout(vector<wormhole> const links)
{
	output_wormhole_list(std::cout,links);
}
