#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

const int MAXN = 5010;
const int INF = 0x3f3f3f3f;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

struct Edge {
	int u, v, c, next;
	Edge(int u0 = 0, int v0 = 0, int c0 = 0, int next0 = 0) {
		u = u0; v = v0; c = c0; next = next0;
	}
} edge[MAXN * 10];
int head[MAXN], cnt; // Ç°ÏòÐÇ´æ´¢½á¹¹

bool visited[MAXN];
int path[MAXN], from, to, maxflow, offflow, nCase, X, Y, P;

void initial() {
	memset(head, -1, sizeof(head));
	cnt = 0;
	maxflow = 0;
}

void addEdge(int u, int v, int c) {
	edge[cnt] = Edge(u, v, c, head[u]);
	head[u] = cnt++;
	edge[cnt] = Edge(v, u, 0, head[v]);
	head[v] = cnt++;
}

int in(int x, int y) {
	return (x - 1)*Y + y;
}
int out(int x, int y) {
	return (x - 1)*Y + y + X*Y;
}

void input() {
	//scanf("%d %d %d", &X, &Y, &P);
	string graph[40], line;
	cin.ignore();
	for (int i = 1; i <= X; i++) {
		graph[i].push_back(' ');
		getline(cin, line);
		graph[i] += line;
		graph[i].push_back(' ');
	}
	from = 0;  to = 2 * X*Y + 1;

	for (int i = 1; i <= X; i++) {
		for (int j = 1; j <= Y; j++) {
			if (graph[i][j] == '*') {
				addEdge(from, in(i, j), 1);
			}
			if (graph[i][j] == '#') {
				addEdge(out(i, j), to, P);
			}
			if (graph[i][j] != '.' && graph[i][j] != '*') {
				addEdge(in(i, j), out(i, j), INF);
			} else if (graph[i][j] == '~') {
				addEdge(in(i, j), out(i, j), 0);
			} else {
				addEdge(in(i, j), out(i, j), 1);
			}
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (x >= 1 && x <= X && y >= 1 && y <= Y) {
					if (graph[x][y] != '~') {
						addEdge(out(i, j), in(x, y), INF);
					}
				}
			}
		}
	}
}

bool bfs(int &min) {
	int s = from, d;
	queue <int> q;
	q.push(s);
	memset(visited, false, sizeof(visited));
	while (!q.empty()) {
		s = q.front();
		q.pop();
		//visited[s] = true;
		for (int i = head[s]; i != -1; i = edge[i].next) {
			d = edge[i].v;
			if (!visited[d] && edge[i].c > 0) {
				visited[d] = true;
				if (edge[i].c < min) min = edge[i].c;
				path[d] = i;
				q.push(d);
				if (d == to) return true;
			}
		}
	}
	return false;
}

void work() {
	int min = INF;
	while (bfs(min)) {
		offflow = MAXN;
		/*for (int i = to; i != from; i = edge[path[i]].u) {
			if (edge[path[i]].c < offflow)
				offflow = edge[path[i]].c;
		}*/
		offflow = min;
		for (int i = to; i != from; i = edge[path[i]].u) {
			edge[path[i]].c -= offflow;
			edge[path[i] ^ 1].c += offflow;
		}
		maxflow += offflow;
		min = INF;
	}
}

void output() {
	printf("%d\n", maxflow);
	//cout << maxflow << endl;
}
/*
int Flow() {
	int k, cMin, path[MAXN];
	bool vis[MAXN];
	queue <int> q;
	int res = 0;

	while (true) {
		memset(vis, false, sizeof(vis));
		vis[from] = true;
		q.push(from);
		cMin = INF;

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v = head[u]; v != -1; v = edge[v].next) {
				if (!vis[k = edge[v].v] && edge[v].c) {
					vis[k] = true;
					path[k] = v;
					q.push(k);
					if (cMin > edge[v].c)
						cMin = edge[v].c;
				}
			}
		}
		if (!vis[to]) break;
		for (int u = to; u != from; u = edge[path[u]].u) {
			edge[path[u]].c -= cMin;
			edge[path[u] ^ 1].c += cMin;
		}
		res += cMin;
	}
	if (res == B) return 1;
	else return 0;
}
*/
int main() {
	//freopen("output.txt", "w", stdout);
	//scanf("%d", &nCase);
	while (cin >> X >> Y >> P) {
		initial();
		input();
		work();
		output();
		/*if (Flow()) {
			printf("possible\n");
		} else {
			printf("not possible\n");
		}*/
	}
	return 0;
}
