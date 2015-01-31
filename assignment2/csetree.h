#pragma once
#ifndef CSETREE_H
#define CSETREE_H
#include <string>
#include <memory>
#include <functional>
#include "parsetreemap.h"


class CSETree
{
private:
	std::string id;
	std::unique_ptr<CSETree> left,right;
	static CSETree constructor_helper(ParseTree const * const in_root,
									  size_t const & node_count);
public:
	CSETree(ParseTree const * const in_root, size_t const & node_count);
	CSETree(ParseTree const * const in_node, ParseTreeMap map, unsigned int &n);

	std::string to_string() const;
};

#endif // CSETREE_H
