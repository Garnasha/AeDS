#pragma once
#ifndef PARSETREE_H
#define PARSETREE_H
#include <string>
#include <memory>
#include <functional>

//load of get methods, very tempting to just declare all member fields
//as public const, but I'm not sure how that'd play with the constructor.
//
//either way, I think I've made this entire class immutable now,
//which is correct for the algorithm it's used in.
//it just takes a lot of const qualifiers, not sure what that does for clarity
class ParseTree
{
private:
	std::string const id;
	std::unique_ptr<ParseTree> const left,right;
	size_t const hashval;
public:
	ParseTree(std::string identifier);//leaf
	ParseTree(std::string identifier,
			  std::unique_ptr<ParseTree> left_child,
			  std::unique_ptr<ParseTree> right_child);//node
	bool is_leaf() const;
	ParseTree const * get_left() const;
	ParseTree const * get_right() const;
	size_t get_hash() const;
	std::string const get_id() const;

	bool operator==(ParseTree const & rhs) const;
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
