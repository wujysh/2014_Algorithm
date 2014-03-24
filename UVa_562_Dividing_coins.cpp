#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 50010;
int nCase, n, sum = 0, coin[110];
bool dp[MAXN];

void init() {
    memset(dp, false, sizeof(dp));
    dp[0] = true;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
        sum += coin[i];
    }
}

void work() {
    for (int i = 0; i < n; i++) {
        for (int v = sum; v >= coin[i]; v--) {
            if (dp[v - coin[i]]) {
                dp[v] = true;
            }
        }
    }
}

void output() {
    for (int v = sum / 2; v >= 0; v--) {
        if (dp[v]) {
            cout << sum - 2 * v << endl;
            break;
        }
    }
}

int main() {
	cin >> nCase;
	while (nCase--) {
        init();
        input();
        work();
        output();
	}
	return 0;
}
