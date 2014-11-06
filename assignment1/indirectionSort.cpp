#include "indirectionSort.h"

using std::vector;

typedef vector<vector<unsigned int>> coord_list;

vector<vector<unsigned int>> gen_coord_list(unsigned int dimension){
	vector<vector<unsigned int>>  coord_list;
	for(unsigned int i = 0; i < dimension; ++i){
		for(unsigned int j = i + 1; j < dimension; ++j){
			coord_list.push_back(vector<unsigned int>{i,j});
		}
	}
	return coord_list;
}


template<typename T>
matrix_coord_comp<T>::matrix_coord_comp(
		std::vector<std::vector<T> > const &_backing_matrix):
	backing_matrix(_backing_matrix)
{

}

template<typename T>
bool matrix_coord_comp<T>::operator()(const std::vector<unsigned int> lhs,
								   const std::vector<unsigned int> rhs)
{
	return backing_matrix[lhs[0]][lhs[1]] < backing_matrix[rhs[0]][rhs[1]];
}

template class matrix_coord_comp<int>;


coord_list gen_sorted_coords(
		vector<vector<int> > const &matrix)
{
	coord_list coords = gen_coord_list(matrix.size());
	std::sort(coords.begin(),coords.end(),matrix_coord_comp<int>(matrix));
	return coords;
}
