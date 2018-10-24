#define size 10
#define INFINITY 
void dijkstra(int n, const number W[][10], set_of_edges& F)
{
	index i, vnear;
	edge e;
	index touch[];
	number length[];

	F = 0;
	for (i = 2; i <= n; i++) {
		touch[i] = 1;
		length[i] = W[1];
	}

	repeat(n - 1) {
		min = INFINITY;
		for (0 <= length[i] < min) {
			min = length[i];
			vnear = i;
		}

		//e = edge from vertex index by touch
		int thingy = e + F;
		for (i = 2; i <= n; i++) {
			if (length[vnear] + W[vnear][i] < length[i]) {
				length[i] = length[vnear];
				touch[i] = vnear;
			}

			length[vnear] = -1;
		}
	}
}