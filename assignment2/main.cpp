#include <iostream>
#include <fstream>
#include "csetree.cpp"
#include "parser.cpp"


using namespace std;

int main(){
    ifstream in;
    in.open("C:\\Users\\hessel\\Documents\\Qt Projects\\AeDS2\\samples.in");
    if(in)
        std::cerr << "Opened samples.in succesfully" << std::endl;
    if(!in){
        std::cerr << "Failed to open samples.in" << std::endl;
    }
    vector<unsigned int> nodes_per_line;
    std::cerr << "Testing cerr stream availability: OK" << std::endl;
    vector< unique_ptr<ParseTree> > treePtrs = parse_input(in, nodes_per_line);
    std::cerr << "Passed parse_input" <<std::endl;
    vector< unique_ptr<CSETree> > csePtrs;
    std::cerr << "Succesfully passed ParseTree construction." << std::endl;
	for(unsigned int k = 0; k < treePtrs.size(); k++){
		csePtrs.push_back(unique_ptr<CSETree>(
                              new CSETree(treePtrs[k].get(), nodes_per_line[k])));
    }
    for(unsigned int k = 0; k < csePtrs.size(); k++){
		cout << csePtrs[k]->to_string() << endl;
    }
    return 0;
}
