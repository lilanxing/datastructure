#ifndef DFS_H
#define DFS_H

#include <iostream>
#include <stack>

#define N 5

const int GRAPH[N][N] = {
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 1, 0, 0},
    {1, 1, 0, 0, 1},
    {0, 0, 1, 0, 0}
};

int VISITED[N];

inline void visit(const int v) {std::cout << v + 1 << std::endl;}

void DFS(const int G[][N], const int v) {
    visit(v);
    VISITED[v] = 1;
    for (int i = 0; i < N; ++i) {
	if (G[v][i] == 1 && !VISITED[i]) {
	    DFS(G, i);
	}
    }
}

void DFSTraverse(const int G[][N]) {
    for (int i = 0; i < N; ++i) VISITED[i] = 0;
    for (int i = 0; i < N; ++i) {
	if (!VISITED[i]) {
	    std::cout << "==== " << i + 1 << " ====" << std::endl;
	    DFS(G, i);
	}
    }
    std::cout << std::endl;
}

void DFSNoRecursive(const int G[][N], int v) {
    std::stack<int> S;
    S.push(v);
    visit(v);
    VISITED[v] = 1;

    while (!S.empty()) {
	v = S.top();
	int i = 0;
	for (i = 0; i < N; ++i) {
	    if (G[v][i] == 1 && !VISITED[i]) {
		S.push(i);
		visit(i);
		VISITED[i] = 1;
		break;
	    }
	}
	if (i == N) {
	    S.pop();
	}
    }
}

void DFSTraverseNoRecursive(const int G[][N]) {
    for (int i = 0; i < N; ++i) VISITED[i] = 0;
    for (int i = 0; i < N; ++i) {
	if (!VISITED[i]) {
	    std::cout << "==== " << i + 1 << " ====" << std::endl;
	    DFSNoRecursive(G, i);
	}
    }
    std::cout << std::endl;
}


int main() {
    DFSTraverse(GRAPH);
    DFSTraverseNoRecursive(GRAPH);
    return 0;
}

#endif
