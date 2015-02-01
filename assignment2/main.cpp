#include <iostream>
#include <fstream>
#include "csetree.h"
#include "parser.h"


using namespace std;

int main(){
	vector<unsigned int> nodes_per_line;
	vector< unique_ptr<ParseTree> > treePtrs = parse_input(std::cin, nodes_per_line);
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
