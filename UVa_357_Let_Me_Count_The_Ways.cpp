#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 30010;
const int coin[5] = { 1, 5, 10, 25, 50 };
long long dp[MAXN];
int sum;

void init() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < 5; i++) {
        for (int v = coin[i]; v < MAXN; v++) {
            dp[v] += dp[v-coin[i]];
        }
    }
}

void output() {
    if (dp[sum] > 1) {
        cout << "There are " << dp[sum] << " ways to produce " << sum << " cents change." << endl;
    } else {
        cout << "There is only 1 way to produce " << sum << " cents change." << endl;
    }
}

int main() {
    init();
    while (cin >> sum) {
		output();
	}
    return 0;
}
