#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

using std::istream;
using std::ostream;
using std::vector;
using std::tuple;
using std::size_t;
using std::get;

/* note: signed ints are used for distances because time traveling wormholes
 * are an unlikely but extremely easily caught edge case.
 */
vector<vector<signed int>> read_adjacency_matrix(istream &instream){
	int N;
	instream >> N;
	vector<vector<signed int>> matrix(N,vector(N));
	instream.ignore('-');
	for(size_t i = 0; i < N; ++i){
		for(size_t j = 0; j < N; ++j){
			instream >> matrix[i][j];
		}
	}
	return matrix;
}

void output_wormhole_list(ostream &outstream,
		vector<tuple<unsigned int,unsigned int,signed int>> links){
	outstream << links.size() << "\n-";
	for(auto t : links){
		outstream << '\n' << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t);
	}
	outstream << std::flush;
}



vector<vector<signed int> > adjacencies_from_stdin()
{
	return read_adjacency_matrix(std::cin);
}


void wormholes_to_stdout(
		vector<tuple<unsigned int, unsigned int, signed int> > links)
{
	output_wormhole_list(std::cout,links);
}
