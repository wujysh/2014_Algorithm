#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 7500;
long long dp[5][MAXN];
const int coin[5] = {1, 5, 10, 25, 50};
//long long dp1[MAXN];
int sum;

void init() {
    memset(dp, -1, sizeof(dp));
}

long long DP(int x, int sum) {
    if (dp[x][sum] != -1) return dp[x][sum];

    if (sum == 0) {
        return dp[x][sum] = 1;
    }

    dp[x][sum] = 0;
    for (int i = x; i < 5 && sum >= coin[i]; i++) {
        dp[x][sum] += DP(i, sum-coin[i]);
    }
    return dp[x][sum];
}

void work() {
    //cout << DP(0, sum) << endl;
    printf("%d\n", DP(0, sum));

//    memset(dp1, 0, sizeof(dp1));
//    dp1[0] = 1;
//    int coins[6] = {0, 1, 5, 10, 25, 50};
//    for (int i = 1; i <= 5; i++) {
//        for (int v = coins[i]; v < 100; v++) {
//            dp1[v] += dp1[v-coins[i]];
//        }
//    }
//    cout << dp1[sum] << endl;
}

int main() {
    init();
    while (scanf("%d", &sum) == 1) {
        work();
    }
    return 0;
}
