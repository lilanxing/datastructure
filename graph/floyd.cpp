#include <iostream>
#include <iomanip>

#define INF 99999
#define V 4

void printSolution(int dist[][V]) {
    for (int i = 0; i < V; ++i) {
	for (int j = 0; j < V; ++j) {
	    if (dist[i][j] == INF) std::cout << std::setw(3) << "INF" << " ";
	    else std::cout << std::setw(3) << dist[i][j] << " ";
	}
	std::cout << std::endl;
    }
}

void floyd(int G[][V]) {
    int dist[V][V];
    for (int i = 0; i < V; ++i) {
	for (int j = 0; j < V; ++j) {
	    dist[i][j] = G[i][j];
	}
    }

    for (int v = 0; v < V; ++v) {
	for (int i = 0; i < V; ++i) {
	    for (int j = 0; j < V; ++j) {
		if (dist[i][v] + dist[v][j] < dist[i][j]) {
		    dist[i][j] = dist[i][v] + dist[v][j];
		}
	    }
	}
    }

    printSolution(dist);
}

int main() {
    int GRAPH[V][V] = {
	{0, 5, INF, 10},
	{INF, 0, 3, INF},
	{INF, INF, 0, 1},
	{INF, INF, INF, 0}
    };
    floyd(GRAPH);
    
    return 0;
}
