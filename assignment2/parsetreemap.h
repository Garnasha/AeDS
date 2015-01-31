#pragma once
#ifndef PARSETREEMAP_H
#define PARSETREEMAP_H
#include <parsetree.h>
#include <functional>
#include <unordered_map>

namespace std {
//my compiler complained when specializing std::hash as in cppreference examples
template <>
struct hash<ParseTree *>{
	size_t operator()(ParseTree * const p) const{
		return p->get_hash();
	}
};
}


//note: I know of std::equal_to, but didn't want to universally define
//equality of ParseTree*'s to be equality of targets, instead of identity
//of targets.
class ParseTree_ptr_equal_to{
public:
	bool operator()(ParseTree * const lhs,ParseTree * const rhs) const{
		return (lhs->get_hash() == rhs->get_hash()) //short-circuit
				&& (*lhs == *rhs);
	}
};

typedef std::unordered_map<
	ParseTree *,
	unsigned int,
	std::hash<ParseTree *>,
	ParseTree_ptr_equal_to
		> ParseTreeMap;

#endif // PARSETREEMAP_H
