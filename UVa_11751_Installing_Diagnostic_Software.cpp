#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1010;
vector<int> g[MAXN];
int n, m;
bool visited[MAXN];

struct line {
    int from, to;
    line(int from, int to): from(from), to(to) {}
    friend bool operator<(line a, line b) {
        if (a.from != b.from) return a.from > b.from;
        else return a.to < b.to;
    }
};
vector<line> vl;

void init() {
    vl.clear();
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) g[i].clear();
}

void input() {
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        vl.push_back(line(a, b));
    }
}

void work() {
    sort(vl.begin(), vl.end());

    for (int i = 0; i < vl.size(); ) {
        int t = vl[i].from, j = i;
        while (vl[j].from == t && j < vl.size()) {
            g[t].push_back(vl[j].to);
            g[vl[j].to].push_back(t);
            j++;
        }
        i = j;
    }
    for (int i = n-1; i >= 0; i--) {
        bool flag = 0;
        if (visited[i]) continue;
        for (int k = 0; k < g[i].size(); k++) {
            if (g[g[i][k]].size() == 0) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            visited[i] = 1;
        } else {
            for (int k = 0; k < g[i].size(); k++)
                visited[g[i][k]] = 1;
        }
    }
}

void output() {
    for (int i = 0; i < n; i++)
        cout << visited[i];
    cout << endl;
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
