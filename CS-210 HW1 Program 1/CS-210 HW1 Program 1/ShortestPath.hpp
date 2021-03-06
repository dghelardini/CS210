//Names: Daelyn Ghelardini, Nicole Lawson, Natalia Sobery, Mia Walker
//Class: CS-210-01
//Homework Assignment #1
//Chapter 3: Exercise #8

#ifndef SHORTESTPATH_GUARD
#define SHORTESTPATH_GUARD

#define  SIZE 5

#include <iostream>

int main()
{
	//adjacent vertices

}

class ShortestPath
{
	int A[SIZE][SIZE];

	//Algorithm 3.4 from book
	//W[][] is the matrix for the original graph
	//D[][] is the matrix for the weights of W
	//P[][] is the matrix is the adjacency
	template <class T>
	void floyd2(int n, const T W[SIZE][SIZE], T D[SIZE][SIZE], T P[SIZE][SIZE])
	{
		int index, i, j, k;

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				P[i][j] = 0;
			}
		}
		D = W;
		
		for (k = 1; k <= n; k++)
		{
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					if (D[i][k] + D[k][j] < D[i][j])
					{
						D[i][j] = k;
						D[i][j] = D[i][k] + D[k][j];
					}
				}
			}
		}
	}

	//Algorithm 3.5 from book
	void path(int q, int r)
	{
		if (P[q][r] != 0)
		{
			path(q, P[q][r]);
			std::cout << "v" << P[q][r];
			path(P[q][r], r);
		}
	}

};

#endif // !SHORTESTPATH_GUARD