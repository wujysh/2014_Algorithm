#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 5000;
struct Edge {
	int u, v, c, next;
	Edge(int u0 = 0, int v0 = 0, int c0 = 0, int next0 = 0) {
		u = u0; v = v0; c = c0; next = next0;
	}
} edge[MAXN * 10];
int head[MAXN * 2], cnt; // Ç°ÏòÐÇ´æ´¢½á¹¹

bool visited[MAXN * 2];
int path[MAXN * 2], from, to, maxflow, offflow, nCase, n;

void init() {
	memset(head, -1, sizeof(head));
	cnt = 0;
	nCase++;
	maxflow = 0;
}

void addEdge(int u, int v, int c) {
	edge[cnt] = Edge(u, v, c, head[u]);
	head[u] = cnt++;
}

void input() {
	int m;
	cin >> from >> to >> m;
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		addEdge(a, b, t);
		addEdge(b, a, 0);
		addEdge(b, a, t);
		addEdge(a, b, 0);
	}
}

bool bfs() {
	int s = from, d;
	queue <int> q;
	q.push(s);
	memset(visited, false, sizeof(visited));
	while (!q.empty()) {
		s = q.front();
		q.pop();
		visited[s] = true;
		for (int i = head[s]; i != -1; i = edge[i].next) {
			d = edge[i].v;
			if (!visited[d] && edge[i].c > 0) {
				path[d] = i;
				q.push(d);
				if (d == to) return true;
			}
		}
	}
	return false;
}

void work() {
	while (bfs()) {
		offflow = MAXN;
		for (int i = to; i != from; i = edge[path[i]].u) {
			if (edge[path[i]].c < offflow)
				offflow = edge[path[i]].c;
		}
		for (int i = to; i != from; i = edge[path[i]].u) {
			edge[path[i]].c -= offflow;
			edge[path[i] ^ 1].c += offflow;
		}
		maxflow += offflow;
	}
}

void output() {
	cout << "Network " << nCase << endl;
	cout << "The bandwidth is " << maxflow << "." << endl << endl;
}

int main() {
	while (cin >> n && n) {
		init();
		input();
		work();
		output();
	}
	return 0;
}
