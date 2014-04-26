#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const long long INF = 1 << 30;
const double eps = 1e-8;
const int MAXN = 50;
const int MAXM = 2500;
struct Edge {
	int u, v, next;
	long long c;
	double w;
	Edge(int u0 = 0, int v0 = 0, long long c0 = 0, double w0 = 0, int next0 = 0) {
		u = u0; v = v0; c = c0; w = w0; next = next0;
	}
} edge[MAXM * 4];
int head[MAXN], cnt;

bool visited[MAXN];
int path[MAXN], from, to, n, m;
double dist[MAXN], ans;

void init() {
	memset(head, -1, sizeof(head));
	cnt = 0;
}

void addEdge(int u, int v, long long c, double w) {
	edge[cnt] = Edge(u, v, c, w, head[u]);
	head[u] = cnt++;
	edge[cnt] = Edge(v, u, 0, -w, head[v]);
	head[v] = cnt++;
}

void input() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            double w;
            cin >> w;
            addEdge(j, m+i, 1, w);
        }
        addEdge(m+i, m+n+1, 1, 0);
    }
    for (int i = 1; i <= m; i++) {
        addEdge(0, i, 1, 0);
    }

    from = 0;  to = m+n+1;
}

bool findPath() {
	queue <int> q;
	memset(visited, false, sizeof(visited));
	memset(path, -1, sizeof(path));
    fill(dist, dist+MAXN, INF);

	dist[from] = 0;
	visited[from] = true;
	q.push(from);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (edge[i].c > 0 && dist[u] + edge[i].w + eps < dist[v]) {
                dist[v] = dist[u] + edge[i].w;
                path[v] = i;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
		}

		visited[u] = false;
	}

	return dist[to] != INF;
}

double MinCostMaxFlow() {
    long long offflow, maxflow = 0;
    double ret = 0;

	while (findPath()) {
		offflow = INF;
		for (int i = path[to]; i != -1; i = path[edge[i].u]) {
			offflow = min(offflow, edge[i].c);
		}
		for (int i = path[to]; i != -1; i = path[edge[i].u]) {
			edge[i].c -= offflow;
			edge[i ^ 1].c += offflow;
		}
		maxflow += offflow;
		ret += dist[to] * offflow;
	}

	return maxflow == n ? ret : -1;
}

void work() {
    ans = MinCostMaxFlow();
}

void output() {
    cout << fixed << setprecision(2) << ans / n + eps << endl;
}

int main() {
    ios::sync_with_stdio(false);
	while (cin >> n >> m && (n || m)) {
		init();
		input();
		work();
		output();
	}
	return 0;
}

