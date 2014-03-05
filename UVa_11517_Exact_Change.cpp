#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
const int INF = 0x3f3f3f3f;
int dp[MAXN], nCase, n, sum, money[100];

void init() {
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
}

void input() {
    cin >> sum;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> money[i];
    }
}

void work() {
    for (int i = 0; i < n; i++) {
        for (int v = MAXN; v >= money[i]; v--) {
            dp[v] = min(dp[v], dp[v-money[i]] + 1);
        }
    }
}

void output() {
    for (int i = sum; i < MAXN; i++) {
        if (dp[i] != INF) {
            cout << i << " " << dp[i] << endl;
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
}
