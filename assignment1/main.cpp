#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	cout << "Hello World!" << endl;
	Matrix<int> foo(2,4);
	foo[1][2] = 2;
	for(auto row : foo){
		for(auto member : row){
			std::cout << member;
		}
		std::cout << endl;
	}
	return 0;
}

