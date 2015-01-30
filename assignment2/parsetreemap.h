#ifndef PARSETREEMAP_H
#define PARSETREEMAP_H
#include <parsetree.h>
#include <functional>

template <>
class std::hash<ParseTree*>{
public:
	size_t operator()(ParseTree *p){
		return p->get_hash();
	}
};



struct {
	int foo;
} bar;

#endif // PARSETREEMAP_H
