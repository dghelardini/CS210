#ifndef Djikstra_GUARD
#define Djikstra_GUARD

#include <iostream>
#include <vector> //like a dynamically sized array
#include <queue> http://www.cplusplus.com/reference/queue/queue/
#include <climits> //http://www.cplusplus.com/reference/climits/

// storing graph edges
struct Edge {
	int start, dest, weight; //start is source
};

// store heap nodes
struct Node {
	int vertex, weight;
};

class Graph {
public:
	std::vector<std::vector<Edge>> adjacencyList; //vector of Edge to show adjacency list.  Also vector info: https://www.codeguru.com/cpp/cpp/cpp_mfc/stl/article.php/c4027/C-Tutorial-A-Beginners-Guide-to-stdvector-Part-1.htm
	Graph(std::vector<Edge> const &graphEdges, int N) //construct graph.  graph edges and number of elements (N)
	{
		//make vector of N elements into correct size
		adjacencyList.resize(N); //http://www.cplusplus.com/reference/vector/vector/resize/
		for (Edge const &graphEdge : graphEdges) //for every edge, add an edge to graphEdges vector
		{
			adjacencyList[graphEdge.start].push_back(graphEdge);
			//insert the edge at the end with built in queue function
		}
	}
};

void print_path(std::vector<int> const &previous, int numVertex)
{
	if (numVertex < 0)
		return;
	print_path(previous, previous[numVertex]); //show the path we took
	std::cout << numVertex << " ";
}

struct comparison //put heap in order
{
	bool operator()(const Node &lhs, const Node &rhs)//
	{
		return lhs.weight > rhs.weight; //right and left sides
	}
};


void DjikstraAlg(Graph const& graph, int start, int N) {
	//https://stackoverflow.com/questions/2786398/is-there-an-easy-way-to-make-a-min-heap-in-c 
	//this is how we learned to make a min heap quickly
	std::priority_queue<Node, std::vector<Node>, comparison> min_heap; //don't forget to put std:: in front of standard library items!
	min_heap.push({ start, 0 }); //push a source node onto heap.  It has a distance of zero.

	std::vector<int> distance(N, INT_MAX);
	distance[start] = 0;
	std::vector<bool> foundMin(N, false); //array stores the ones with the lowest cost so we don't go over it again
	foundMin[0] = true;
	// stores predecessor of a vertex (to print path)
	std::vector<int> previous(N, -1);

	while (!min_heap.empty()) //only runs if the min_heap has items (aka not empty)
	{
		Node node = min_heap.top(); // built in queue function that returns top
		min_heap.pop(); //lowest value pops
		int u = node.vertex;  // get vertex number
		for (auto numVertex : graph.adjacencyList[u]) // do for each neighbor v of u
		{
			int v = numVertex.dest; //destination vertex
			int weight = numVertex.weight;

			// Relax the edges https://stackoverflow.com/questions/12782431/relaxation-of-an-edge-in-dijkstras-algorithm
			if (!foundMin[v] && (distance[u] + weight) < distance[v])
			{
				distance[v] = distance[u] + weight;
				previous[v] = u;
				min_heap.push({ v, distance[v] });
			}
		}

		// marked vertex u as done so we don't do it again
		foundMin[u] = true;
	}

	for (int z = 1; z < N; ++z) //iterate through paths
	{
		std::cout << "Path from vertex 0 to vertex " << z << " has minimum "
			"cost of " << distance[z] << " and the route is [ ";
		print_path(previous, z);
		std::cout << "]\n";
	}
}


int main() //test it
{
	
	std::vector<Edge> graphEdges = //make the edges
	{  
		{ 0, 1, 10 },{ 0, 4, 3 },{ 1, 2, 2 },{ 1, 4, 4 },{ 2, 3, 9 },
		{ 3, 2, 7 },{ 4, 1, 1 },{ 4, 2, 8 },{ 4, 3, 2 }
	};

	
	int N = 5; // Number of nodes in the graph
	Graph graph(graphEdges, N); //make the graph
	DjikstraAlg(graph, 0, N); //run the algorithm

	return 0;

	//system("pause");
}


#endif