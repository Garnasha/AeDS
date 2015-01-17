#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <memory>
#include <string>

class ExpressionTree
{
private:
	// doing manual type disambiguation is easier than hand-hacking
	// a proper algebraic data type
	enum Type{NODE,LEAF,ELIMINATED} type;
	std::string var_name;
	unsigned int ref_no;
	std::shared_pointer<ExpressionTree> left,right;
	size_t hash;
public:
	ExpressionTree();
	
};



#endif // EXPRESSIONTREE_H
