#ifndef Djikstra_GUARD
#define Djikstra_GUARD

#include <iostream>
#include <vector>
#include <queue>
#include <climits> //http://www.cplusplus.com/reference/climits/

// Data structure for storing graph edges
struct Edge {
	int start, dest, weight; //start is source
};

// store heap nodes
struct Node {
	int vertex, weight;
};

class ourGraph {
public:
	vector<vector<Edge>> adjacencyList; //vector of Edge to show adjacency list
	Graph(vector<Edge> const &graphEdges, int N) //construct graph.  graph edges and number of elements (N)
	{
		//make vector of N elements into correct size
	
		adjacencyList.resize(N); //http://www.cplusplus.com/reference/vector/vector/resize/
		for (Edge const &graphEdge : graphEdges) //for every edge, add an edge to graphEdges vector
		{
			adjacencyList[graphEdge.start].push_back(graphEdge);
			//insert the edge at the end
		}
	}
};

struct comparison //put heap in order
{
	bool(const Node &lhs, int start, int N)
	{
		return lhs.weight > rhs.weight; 
	}

};

void print_path(vector<int> const &previous, int numVertex)
{
	if (numVertex < 0)
		return;

	print_path(previous, previous[numVertex]); //show the path we took
	std::cout << numVertex << " ";
}

// boolean array to track vertices for which minimum
// cost is already found
vector<bool> foundMin(N, false);
foundMin[0] = true;

// stores predecessor of a vertex (to print path)
vector<int> previous(N, -1);

void DjikstraAlg(ourGraph const& graphing, int start, int N) {
	//https://stackoverflow.com/questions/2786398/is-there-an-easy-way-to-make-a-min-heap-in-c 
	//this is how we learned to make a min heap quickly
	priority_queue<Node, vector<Node>, comparison> min_heap;
	min_heap.push({ start, 0 }); //push a source node onto heap.  It has a distance of zero.

	vector<int> distance(N, INT_MAX);
	distance[start] = 0;

	// run till min_heap is not empty
	while (!min_heap.empty())
	{	Node node = min_heap.top(); // Remove and return best vertex
		min_heap.pop();

		// get vertex number
		int u = node.vertex;

		for (auto numVertex : graphing.adjacencyList[u]) // do for each neighbor v of u
		{
			int v = numVertex.dest; //destination vertex
			int weight = numVertex.weight;

			// Relax the edges
			if (!foundMin[v] && (distance[u] + weight) < distance[v])
			{	distance[v] = distance[u] + weight;
				previous[v] = u;
				min_heap.push({ v, distance[v] });
			}
		}

		// marked vertex u as done so we don't do it again
		foundMin[u] = true;
	}

	for (int i = 1; i < N; ++i)
	{
		std::cout << "Path from vertex 0 to vertex " << i << " has minimum "
			"cost of " << distance[numVertex] << " and the route is [ ";
		print_path(previous, numVertex);
		std::cout << "]\n";
	}
}

// main function
int main()
{
	//make the edgess
	vector<Edge> graphEdges =
	{
	{ 0, 1, 10 },{ 0, 4, 3 },{ 1, 2, 2 },{ 1, 4, 4 },{ 2, 3, 9 },
	{ 3, 2, 7 },{ 4, 1, 1 },{ 4, 2, 8 },{ 4, 3, 2 }
	};

	// Number of nodes in the graph
	int N = 5;
	Graph graphEdge(graphEdges, N); //make the graph
	DjikstraAlg(graphing, 0, N);

	return 0;
}


#endif