#include "parser.h"

using namespace std;

unique_ptr<ParseTree> parse_line(string line, unsigned int& line_ind, unsigned int &nr_nodes){
    string name = "";
    for(; line_ind < line.size(); line_ind++){
        if(line[line_ind] == '('){
            nr_nodes++;
            unique_ptr<ParseTree> ptr(new ParseTree(move(name), parse_line(line, line_ind, nr_nodes), parse_line(line, line_ind, nr_nodes)));
            return ptr;
        }
        if(line[line_ind] == ')' || line[line_ind] == ',' || (line[line_ind] == '\n' && name.size() > 0)){
            nr_nodes++;
            unique_ptr<ParseTree> ptr(new ParseTree(move(name)));
            return ptr;
        }
        name += line[line_ind];
    }
    return nullptr;
}

vector<string> read_lines(istream& in, const unsigned int amnt_lines){
    vector<string> lines;
    for(unsigned int k = 0; k < amnt_lines; k++){
        string line = "";
        bool stop = false;
        for(unsigned int l = 0; l < max_length && !stop; l++){
            char a;
            in.get(a);
            line += a;
            if(a == '\n'){
                stop = true;
            }
        }
        lines.push_back(line);
    }
    return lines;
}

vector< unique_ptr<ParseTree> > parse_input(istream& in, unsigned int& nr_nodes){
    vector< unique_ptr<ParseTree> > treePtrs;
    unsigned int amnt_lines;
    in >> amnt_lines;
    in.get();
    vector<string> lines = read_lines(in, amnt_lines);
    for(unsigned int k = 0; k < amnt_lines; k++){
        unsigned int line_ind = 0;
        treePtrs.push_back(parse_line(lines[k], line_ind, nr_nodes));
    }
    return treePtrs;
}
