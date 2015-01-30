#ifndef CSETREE_H
#define CSETREE_H
#include <string>
#include <memory>
#include <functional>
#include <unordered_map>


class CSETree
{
private:
	std::string id;
	std::unique_ptr<CSETree> left,right;
public:
	CSETree();
};

#endif // CSETREE_H
