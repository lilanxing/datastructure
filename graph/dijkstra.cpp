#include <iostream>

#define V 9

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX;
    int min_index = 0;

    for (int v = 0; v < V; ++v) {
	if (sptSet[v] == false && dist[v] <= min) {
	    min = dist[v];
	    min_index = v;
	}
    }

    return min_index;
}

void printPath(int parent[], int i) {
    if (parent[i] == -1) return;
    printPath(parent, parent[i]);
    std::cout << i << " ";
}

void printSoluton(int src, int dist[], int parent[]) {
    std::cout << "Vertex\tDistance\tPtah" << std::endl;
    for (int i = 0; i < V; ++i) {
	if (src == i) continue;
	std::cout << src << "->" << i << "\t" << dist[i] << "\t" << src << " ";
	printPath(parent, i);
	std::cout << std::endl;
    }
}

void dijkstra(int G[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; ++i) {
	parent[0] = -1;
	dist[i] = INT_MAX;
	sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; ++count) {
	int u = minDistance(dist, sptSet);
	sptSet[u] = true;

	for (int v = 0; v < V; ++v) {
	    if (!sptSet[v] && G[u][v] && dist[u] + G[u][v] < dist[v]) {
		parent[v] = u;
		dist[v] = dist[u] + G[u][v];
	    }
	}
    }

    printSoluton(src, dist, parent);
}

int main() {
    int GRAPH[V][V] = {
	{0, 4, 0, 0, 0, 0, 0, 8, 0},
	{4, 0, 8, 0, 0, 0, 0, 11, 0},
	{0, 8, 0, 7, 0, 4, 0, 0, 2},
	{0, 0, 7, 0, 9, 14, 0, 0, 0},
	{0, 0, 0, 9, 0, 10, 0, 0, 0},
	{0, 0, 4, 0, 10, 0, 2, 0, 0},
	{0, 0, 0, 14, 0, 2, 0, 1, 6}, 
	{8, 11, 0, 0, 0, 0, 1, 0, 7}, 
	{0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    dijkstra(GRAPH, 0);
    
    return 0;
}
