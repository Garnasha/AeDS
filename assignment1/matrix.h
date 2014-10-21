#pragma once
#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
public:
	Matrix(auto rows, auto columns);
	auto operator[](auto i);
};
#include "Matrix.cpp"
#endif // MATRIX_H
