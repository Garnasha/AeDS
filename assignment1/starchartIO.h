#ifndef STARCHARTIO_H
#define STARCHARTIO_H

#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

std::vector<std::vector<signed int>> read_adjacency_matrix(
		std::istream &instream);

void output_wormhole_list(
		std::ostream &outstream,
		std::vector<std::tuple<unsigned int,unsigned int,signed int>> links);

std::vector<std::vector<signed int>> adjacencies_from_stdin();

void wormholes_to_stdout(
		std::vector<std::tuple<unsigned int,unsigned int,signed int>> links);

#endif // STARCHARTIO_H
