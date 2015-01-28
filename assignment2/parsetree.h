#ifndef PARSETREE_H
#define PARSETREE_H
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <functional>

class ParseTree
{
private:
	std::string id;
	std::unique_ptr<ParseTree> left,right;
	size_t hashval;
public:
	ParseTree(std::string identifier);//leaf
	ParseTree(std::string identifier,
			  std::unique_ptr<ParseTree> left_child,
			  std::unique_ptr<ParseTree> right_child);//node
	bool is_leaf();
	ParseTree* get_left();
	ParseTree* get_right();
	size_t get_hash();

	bool operator==(const ParseTree& rhs);
};

/*
given
string foo;
to create a unique_ptr to a leaf with foo as id, do:
unique_ptr<ParseTree> foo_ptr(new ParseTree(foo));
After this, foo is in an undefined but valid state: likely the empty string.
to re-use foo, first do
foo = "";
*/

#endif // PARSETREE_H
