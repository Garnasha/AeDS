#ifndef INDIRECTIONSORT_H
#define INDIRECTIONSORT_H\

#include <algorithm>
#include <vector>

std::vector<std::vector<unsigned int>> gen_coord_list(unsigned int dimension);

/* Template explicitly instantiated for:
 * matrix_coord_comp<int>
 */
template <typename T>
class matrix_coord_comp{
private:
	std::vector<std::vector<T>> const &backing_matrix;
public:
	matrix_coord_comp(std::vector<std::vector<T>> const &_backing_matrix);
	bool operator()(const std::vector<unsigned int> lhs,
					const std::vector<unsigned int> rhs);
};

std::vector<std::vector<unsigned int>> gen_sorted_coords(
		std::vector<std::vector<int>> const &matrix);

#endif // INDIRECTIONSORT_H
