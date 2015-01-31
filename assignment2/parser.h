#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include "parsetree.h"

const unsigned int max_length = 200000;

std::unique_ptr<ParseTree> parse_line(std::string line, unsigned int& line_ind, unsigned int& nr_nodes);

std::vector<std::string> read_lines(std::istream& in, const unsigned int amnt_lines);

std::vector< std::unique_ptr<ParseTree> > parse_input(std::istream& in, std::vector<unsigned int>& nodes_per_line);

#endif // PARSER_H
