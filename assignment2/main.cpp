#include <iostream>
#include <fstream>
#include "csetree.cpp"
#include "parser.cpp"


using namespace std;

int main(){
    ifstream in;
    in.open("samples.in");
    vector<unsigned int> nodes_per_line;
    vector< unique_ptr<ParseTree> > treePtrs = parse_input(in, nodes_per_line);
    vector< unique_ptr<CSETree> > csePtrs;
	for(unsigned int k = 0; k < treePtrs.size(); k++){
		csePtrs.push_back(unique_ptr<CSETree>(
                              new CSETree(treePtrs[k].get(), nodes_per_line[k])));
    }
    for(unsigned int k = 0; k < csePtrs.size(); k++){
		cout << csePtrs[k]->to_string() << endl;
    }
    return 0;
}
