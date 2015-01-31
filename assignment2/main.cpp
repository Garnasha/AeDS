#include <iostream>
#include <fstream>
#include <csetree.cpp>
#include <parser.cpp>

using namespace std;

int main(){
    ifstream in;
    in.open("samples.in");
    unsigned int nr_nodes = 0;
    vector< unique_ptr<ParseTree> > treePtrs = parse_input(in, nr_nodes);
    vector< unique_ptr<CSETree> > csePtrs;
    vector<CSETree> cseTrees;
    for(unsigned int k = 0; k < treePtrs.size(); k++){
        unique_ptr<CSETree> ptr(new CSETree(treePtrs[k].get(), nr_nodes));
        csePtrs.push_back(ptr);
        CSETree newTree(treePtrs[k].get(), nr_nodes);
        cseTrees.push_back(newTree);
    }
    for(unsigned int k = 0; k < cseTrees.size(); k++){
        cout << cseTrees[k].to_string() << endl;
    }
    return 0;
}
