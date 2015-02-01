#pragma once
#ifndef PARSETREEMAP_H
#define PARSETREEMAP_H
#include "parsetree.h"
#include <functional>
#include <unordered_map>

//some minimal helper function object classes here, not making a .cpp for that.
//the important bit is the typedef at the end.

/*
CppReference.com claims this should work fine:
template <>
struct std::hash<ParseTree *>{
blah
};
but the compiler complained, so here goes...
*/
namespace std {
template <>
struct hash<ParseTree *>{
	size_t operator()(ParseTree const * const p) const{
		return p->get_hash();
	}
};
}
//whiny compiler.


//note: I know about std::equal_to, but didn't want to universally define
//equality of ParseTree*'s to be equality of targets, instead of identity
//of targets.
class ParseTree_ptr_equal_to{
public:
	bool operator()(ParseTree const * const lhs,
					ParseTree const * const rhs) const{
		return (lhs->get_hash() == rhs->get_hash()) //short-circuit
				&& (*lhs == *rhs);
	}
};

typedef std::unordered_map<
	ParseTree const * const,
	unsigned int,
	std::hash<ParseTree *>,
	ParseTree_ptr_equal_to
		> ParseTreeMap;

#endif // PARSETREEMAP_H
