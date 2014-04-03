#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
int dp[MAXN][MAXN], last[MAXN][MAXN], n, ans;
struct node {
	int w, s;
	node(int w0 = 0, int s0 = INF) {
        w = w0;  s = s0;
	}
	friend bool operator<(const node a, const node b) {
		return a.s < b.s;
	}
};
vector <node> box;

void init() {
    box.clear();
    box.push_back(node(0, INF));
    memset(dp, 0x3f, sizeof(dp));
    memset(last, -1, sizeof(last));
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    ans = 0;
}

void input() {
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        box.push_back(node(x, y));
    }
}

void work() {
    //sort(box.begin() + 1, box.end());
    reverse(box.begin() + 1, box.end());

	for (int i = 1; i < box.size(); i++) {
		for (int j = 1; j <= i; j++) {
            if (box[i].s >=  dp[i-1][j-1] && i > last[i-1][j-1] && dp[i-1][j-1] + box[i].w < dp[i-1][j]) {
                dp[i][j] = dp[i-1][j-1] + box[i].w;
                last[i][j] = i;
            } else {
                dp[i][j] = dp[i-1][j];
                last[i][j] = last[i-1][j];
            }

            if (dp[i][j] != INF) {
                ans = max(ans, j);
            }
		}
	}
}

void output() {
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n && n) {
        init();
        input();
        work();
        output();
    }
    return 0;
}
