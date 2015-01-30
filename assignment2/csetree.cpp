#include "csetree.h"


CSETree CSETree::constructor_helper(ParseTree * const in_root,
										   const size_t &node_count)
{
	unsigned int n = 0;
	return CSETree(in_root,ParseTreeMap(node_count/2),n);
}

CSETree::CSETree(ParseTree * const in_root, const size_t &node_count):
	CSETree(CSETree::constructor_helper(in_root,node_count))
{

}

CSETree::CSETree(ParseTree * node, ParseTreeMap map, unsigned int &n)
{

	if(map.find(node) == map.end()){
		++n;
		map.insert(std::pair<ParseTree * const,unsigned int>(node,n));
		id = node->get_id();
		if(!node->is_leaf()){
			left = std::unique_ptr<CSETree>(
						new CSETree(node->get_left(),map,n));
			right = std::unique_ptr<CSETree>(
						new CSETree(node->get_right(),map,n));
		}
	}
	else{//node has already been seen, and stored in the map.
		id = std::to_string(map.find(node)->second);
	}
}
std::string CSETree::to_string() const
{
	if(left == nullptr){ //leaf
		return id;
	}
	else{
		return id + "(" + left->to_string() + "," + right->to_string() + ")";
	}

}

