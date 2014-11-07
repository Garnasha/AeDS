#include <iostream>
#include <algorithm>
#include <fstream>
#include "matrix.h"
#include "indirectionSort.h"
#include "starchartIO.h"
#include "wormholeCalc.h"

int main()
{
	std::cout << "Hello World!" << std::endl;
	Matrix<int> foo(2,4);
	foo[1][2] = 2;
	for(auto row : foo){
		for(auto member : row){
			std::cout << member;
		}
		std::cout << std::endl;
	}
	auto tuples = gen_coord_list(5);
	for(auto row : tuples){
		std::cout << "(" << row[0] << ", " << row[1] << "), ";
	}
	std::cout << std::endl;

	std::vector<std::vector<int>> testmatrix(5,std::vector<int>(5));
	testmatrix[2][3] = testmatrix[3][2] = 1;
	testmatrix[2][4] = testmatrix[4][2] = 2;
	testmatrix[0][1] = testmatrix[1][0] = 3;
	for(auto row : testmatrix){
		for(auto member : row){
			std::cout << member;
		}
		std::cout << std::endl;
	}


	matrix_coord_comp<int> comp(testmatrix);
	std::sort(tuples.begin(),tuples.end(),comp);
	for(auto row : tuples){
		std::cout << "(" << row[0] << ", " << row[1] << "), ";
	}

	for(auto row : gen_sorted_coords(testmatrix)){
		std::cout << "(" << row[0] << ", " << row[1] << "), ";
	}
	std::ifstream testinput("example.in");

	auto testmatrix2 = read_adjacency_matrix(testinput);
	for(auto row : testmatrix2){
		for(auto member : row){
			std::cout << member << ',';
		}
		std::cout << std::endl;
	}
	wormholes_to_stdout(calcWormholes(testmatrix2));
	return 0;
}

