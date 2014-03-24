#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 10010;
int track[25], s, n, dp[MAXN];
bool path[25][MAXN];

void init() {
    memset(dp, 0, sizeof(dp));
    memset(path, 0, sizeof(path));
}

void input() {
    for (int i = 1; i <= n; i++) {
        cin >> track[i];
    }
}

void work() {
    for (int i = n; i >= 1; i--) {
        for (int v = s; v >= track[i]; v--) {
            if (dp[v - track[i]] + track[i] > dp[v]) {
                dp[v] = dp[v - track[i]] + track[i];
                path[i][v] = true;
            }
        }
    }
}

void output() {
    int v = s;
    for (int i = 1; i <= n; i++) {
        if (path[i][v]) {
            cout << track[i] << " ";
            v -= track[i];
        }
    }
    cout << "sum:" << dp[s] << endl;
}

int main() {
	while (cin >> s >> n) {
		init();
		input();
		work();
		output();
	}
	return 0;
}
