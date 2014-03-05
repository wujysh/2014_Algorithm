#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 6010;
const int coin[11] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
long long dp[MAXN];
double sum;

void init() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < 11; i++) {
        for (int v = coin[i]; v < MAXN; v++) {
            dp[v] += dp[v-coin[i]];
        }
    }
}

void output() {
    cout << setw(6) << setprecision(2) << fixed << sum;
    cout << setw(17) << dp[int(sum * 20)] << endl;
}

int main() {
    init();
    while (cin >> sum && sum) {
		output();
	}
    return 0;
}
