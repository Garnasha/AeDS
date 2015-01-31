#include "parser.h"

using namespace std;

unique_ptr<ParseTree> parse_line(string line, unsigned int& line_ind, unsigned int &nr_nodes){
    string name = "";
    for(; line_ind < line.size(); line_ind++){
        char c = line.at(line_ind);
        if(c == '('){
            nr_nodes++;
            unique_ptr<ParseTree> ptr(new ParseTree(move(name), parse_line(line, line_ind, nr_nodes), parse_line(line, line_ind, nr_nodes)));
            return ptr;
        }
        if(c == ')' || c == ',' || (c == '\n' && name.size() > 0)){
            nr_nodes++;
            unique_ptr<ParseTree> ptr(new ParseTree(move(name)));
            return ptr;
        }
        name += c;
    }
    return nullptr;
}

vector<string> read_lines(istream& in, const unsigned int amnt_lines){
    vector<string> lines;
	std::cerr << "Entering outer readlines loop" << std::endl;
    for(unsigned int k = 0; k < amnt_lines; k++){
		std::cerr << "readlines outer pass: " << k << " out of " << amnt_lines << std::endl;
        string line = "";
		bool stop = false;
		for(unsigned int l = 0; l < max_length && !stop; l++){
			if(!(l%10000))
				std::cerr << "readlines inner pass: " << l << " out of " << max_length << std::endl;
            char a;
            in.get(a);
            line += a;
            if(a == '\n'){
				std::cerr << "found EOL" << std::endl;
                stop = true;
            }
        }
		std::cerr << "finished inner readlines loop" << std::endl;
        lines.push_back(line);
    }
	std::cerr << "finished outer readlines loop" << std::endl;
    return lines;
}

vector< unique_ptr<ParseTree> > parse_input(istream& in, vector<unsigned int>& nodes_per_line){
	std::cerr << "entering parse_input" << std::endl;

    vector< unique_ptr<ParseTree> > treePtrs;
    unsigned int amnt_lines;
    in >> amnt_lines;
    in.get();
	std::cerr << "about to enter read_lines to read " << amnt_lines << std::endl;
    vector<string> lines = read_lines(in, amnt_lines);
	std::cerr << "Entering parse loop, intending to read " << amnt_lines << std::endl;
	for(unsigned int k = 0; k < amnt_lines; k++){
		std::cerr << "parse loop pass: " << k << std::endl;
        unsigned int nr_nodes = 0;
        unsigned int line_ind = 0;
        treePtrs.push_back(parse_line(lines[k], line_ind, nr_nodes));
        nodes_per_line.push_back(nr_nodes);
    }
	std::cerr << "Finished parse loop" << std::endl;
    return treePtrs;
}
