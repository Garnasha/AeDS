#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include "parsetree.h"

using namespace std;

const unsigned int max_length = 200000;

unique_ptr<ParseTree> parse_line(string line, unsigned int& line_ind);

vector<string> read_lines(istream& in, const unsigned int amnt_lines);

vector< unique_ptr<ParseTree> > parse_input(istream& in);

#endif // PARSER_H
