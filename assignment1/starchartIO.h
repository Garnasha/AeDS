#ifndef STARCHARTIO_H
#define STARCHARTIO_H

#include <iostream>
#include <limits>
#include "starchart_types.h"

std::vector<std::vector<signed int>> read_adjacency_matrix(
		std::istream &instream);

void output_wormhole_list(std::ostream &outstream,std::vector<wormhole> const links);

matrix adjacencies_from_stdin();

void wormholes_to_stdout(std::vector<wormhole> const links);

#endif // STARCHARTIO_H
