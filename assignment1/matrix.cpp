#pragma once
#include "matrix.h"

template <typename T>
Matrix<T>::Matrix(size_type rows, row_size_type columns):
	store(rows,std::vector<T>(columns))
{
}

template <typename T>
typename Matrix<T>::row_type &Matrix<T>::operator[](size_type i){
	return store[i];
}

template <typename T>
typename std::vector<std::vector<T>>::iterator Matrix<T>::begin(){
	return store.begin();
}

template <typename T>
typename std::vector<std::vector<T>>::iterator Matrix<T>::end(){
	return store.end();
}
