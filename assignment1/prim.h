#ifndef PRIM_H
#define PRIM_H

#include <limits>
#include <algorithm>
#include "starchart_types.h"

#ifndef UNREACHABLE
#define UNREACHABLE
distance constexpr unreachable = std::numeric_limits<distance>::max();
#endif

struct prim_minimals{
	struct minpoint{
		bool included;
		index nearest;
		distance dist;
	};
	std::size_t mindex;
	std::vector<minpoint> minimals;
};

std::pair<std::vector<wormhole>,matrix> prim_MST_enhanced(matrix const &input);

//N
prim_minimals prim_init(matrix const &input);

//1
wormhole next_wormhole(prim_minimals const &meta);

//N
void update_minimals(prim_minimals &meta,matrix const &input);

//N
void update_inferred(wormhole const &added,matrix &inferred);

//N^2
matrix gen_blank_inferred(size_t N);


std::vector<wormhole> solve_starchart(matrix const &input);

void find_last_wormhole(matrix const &input,
						matrix const &inferred,
						std::vector<wormhole> &wormholes);

void fill_diagonal(matrix &M, distance n);

#endif // PRIM_H
