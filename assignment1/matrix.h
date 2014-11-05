#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

template <typename T>
class Matrix
{
private:
	std::vector<std::vector<T>> store;
public:
	class row_type{
	private:
		typename std::vector<T>::iterator row_begin;
		typename std::vector<T>::size_type row_size;
	public:
		typedef decltype(row_size) size_type;
		typename std::vector<T>::iterator begin();
		typename std::vector<T>::iterator end();
		T &operator[](size_type);
	};

	typedef typename std::vector<row_type>::size_type size_type;
	typedef typename row_type::size_type  row_size_type;
	Matrix(size_type, row_size_type);
	row_type &operator[](size_type);
	typename std::vector<row_type>::iterator begin();
	typename std::vector<row_type>::iterator end();
};
#include "Matrix.cpp"
#endif // MATRIX_H
