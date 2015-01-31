#include "parsetree.h"

template<int wordsize>
struct phi{};

//64-bit magic number
template<>
struct phi<8>{
	static constexpr size_t value = 0x9e3779b97f4a7c15;
};

//32-bit magic number
template<>
struct phi<4>{
	static constexpr size_t value = 0x9e3779b9;
};

/*
 * cribbing hash_combine from the boost library, with some modification.
 * Good hashing is hard, and this is tried and true.
 * Important difference from the boost version: the boost version takes a
 * hash and a T foo to be hashed, this version takes two hashes.
 */
size_t hash_combine(size_t const& lhs, size_t const& rhs){
	return lhs ^ (rhs + phi<sizeof(size_t)>::value + (lhs << 6) + (lhs >> 2));
}

ParseTree::ParseTree(std::string identifier):
	id(identifier), left(), right(),
	hashval(std::hash<std::string>()(identifier))
{
}

ParseTree::ParseTree(std::string identifier,
					 std::unique_ptr<ParseTree> left_child,
					 std::unique_ptr<ParseTree> right_child):
	id(identifier), left(std::move(left_child)), right(std::move(right_child)),
	hashval(hash_combine(hash_combine(
		std::hash<std::string>()(identifier),
		left->hashval),
		right->hashval))
{
}

bool ParseTree::is_leaf() const
{
	return left == nullptr;
}

ParseTree const * ParseTree::get_left() const
{
	return left.get();
}

ParseTree const * ParseTree::get_right() const
{
	return right.get();
}

size_t ParseTree::get_hash() const
{
	return hashval;
}

std::string const ParseTree::get_id() const
{
	return id;
}


bool ParseTree::operator==(ParseTree const &rhs) const
{
	return (id == rhs.id && (
				(left == rhs.left) || //test for leaf and/or identical
				(*left == *(rhs.left) && *right == *(rhs.right))));
}

