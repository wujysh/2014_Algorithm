#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 6000;
const int INF = 0x3f3f3f3f;
int dp[MAXN][MAXN];
struct node {
	int w, s;
	node(int w1, int s1) {
		w = w1;  s = s1;
	}
	friend bool operator<(const node a, const node b) {
		return a.s < b.s;
	}
};
vector <node> turtle;

void init() {
    turtle.clear();
    turtle.push_back(node(0, INF));
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < turtle.size(); i++) {
        dp[i][0] = 0;
    }
}

void input() {
    int x, y;
	while (cin >> x >> y) {
		turtle.push_back(node(x, y));
	}
}

void work() {
    sort(turtle.begin() + 1, turtle.end());

	for (int i = 1; i < turtle.size(); i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j];
			if (turtle[i].s >= dp[i - 1][j - 1] + turtle[i].w) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + turtle[i].w);
			}
		}
	}
}

void output() {
    int ans = 0;
	for (int i = turtle.size() - 1; i >= 1; i--) {
		if (dp[turtle.size() - 1][i] != INF) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    init();
    input();
    work();
    output();
    return 0;
}
