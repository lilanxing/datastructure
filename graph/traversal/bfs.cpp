#ifndef BFS_H
#define BFS_H

#include <iostream>
#include <queue>

#define N 5

const int GRAPH[N][N] = {
    {0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 0, 0},
    {0, 0, 1, 1, 0}
};

int VISITED[N];

inline void visit(const int v) {std::cout << v + 1 << " ";}

void BFS(const int G[N][N], int v) {
    std::queue<int> Q;
    Q.push(v);
    VISITED[v] = 1;
    visit(v);

    while (!Q.empty()) {
	v = Q.front();
	Q.pop();
	for (int i = 0; i < N; ++i) {
	    if (G[v][i] == 1 && !VISITED[i]) {
		visit(i);
		VISITED[i] = 1;
		Q.push(i);
	    }
	}
    }
}

void BFSTraverse(const int G[N][N]) {
    for (int i = 0; i < N; ++i) VISITED[i] = 0;
    for (int i = 0; i < N; ++i) {
	if (!VISITED[i]) {
	    std::cout << "==== " << i << " ====" << std::endl;
	    BFS(G, i);
	}
    }
    std::cout << std::endl;
}

int main() {
    BFSTraverse(GRAPH);
    return 0;
}

#endif
