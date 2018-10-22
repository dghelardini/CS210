#ifndef Djikstra_GUARD
#define Djikstra_GUARD

#define NUMBER_OF_VERTICES 5
#include <iostream>

template <class T>
class Djikstra
{
	T A[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES];

	//W[][] is the matrix for the original graph
	//D[][] is the matrix for the weights of W
	//P[][] is the the adjacency matrix

	void path(int q, int r)
	{
		if (A[q][r] != 0)
		{
			path(q, A[q][r]);
			std::count << "v" << A[q][r];
			path(A[q][r], r);
		}
		
	}

	int main()
	{
		//adjacent vertices
		int Matrix[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES] = //4 by 4 because we have 4 vertices
		{

			{ 0, INT_MAX, INT_MAX, 4 }, //vertex 0. Ex: Distance from 0 to 2 is -1
		{ 2, 0, 5, INT_MAX }, //for vertex 1
		{ INT_MAX, INT_MAX, 0, -1 }, //vertex 2
		{ INT_MAX, -1, INT_MAX, 0 } //vertex 3

		};

		//Run the algorithm
		//floyd2(Matrix);
		//system("pause");
	}
};

#endif