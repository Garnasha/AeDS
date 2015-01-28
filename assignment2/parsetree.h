#ifndef PARSETREE_H
#define PARSETREE_H
#include <string>
#include <memory>
#include <iostream>
#include <fstream>

class ParseTree
{
	bool leafness;
	std::string id;
	std::unique_ptr<ParseTree> left,right;
	size_t hash;
public:
	ParseTree(std::string&& identifier);
	ParseTree(std::string&& identifier,
			  std::unique_ptr<ParseTree>&& left_child,
			  std::);
	bool is_leaf();
	ParseTree* get_left();
	ParseTree* get_right();
	size_t get_hash();

	bool operator==(const ParseTree& rhs);
};

#endif // PARSETREE_H
