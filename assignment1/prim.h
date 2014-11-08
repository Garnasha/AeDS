#ifndef PRIM_H
#define PRIM_H

#include <limits>
#include "starchart_types.h"

distance constexpr unreachable = std::numeric_limits<distance>::max();

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

prim_minimals prim_init(matrix const &input);

wormhole next_wormhole(prim_minimals const &meta);

void update_minimals(prim_minimals &meta,matrix const &input);

void update_inferred(wormhole const &added,matrix &inferred);

matrix gen_blank_inferred(size_t N);

std::vector<wormhole> solve_starchart(matrix const &input);

wormhole find_last_wormhole(matrix const &input, matrix const &inferred);

void fill_diagonal(matrix M, distance n);

#endif // PRIM_H
