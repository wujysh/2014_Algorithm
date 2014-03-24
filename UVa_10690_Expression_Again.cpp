#include <iostream>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 110;
int N, M, a[MAXN], sum, maxAns, minAns, minNM, maxNM, mina;
bool dp[MAXN][MAXN*MAXN];

void init() {
    memset(dp, false, sizeof(dp));
    sum = minNM = maxNM = 0;
    mina = INF;
}

void input() {
    for (int i = 0; i < N+M; i++) {
        cin >> a[i];
        sum += a[i];
        mina = min(mina, a[i]);
        //a[i] += 50;  // negative numbers
    }
    mina = -mina;
    for (int i = 0; i < N+M; i++) {
        a[i] += mina;
    }
}

void work() {
    minNM = min(N, M);
    maxNM = max(N, M);

    dp[0][0] = true;
    for (int i = 0; i < N+M; i++) {
        for (int j = minNM; j >= 1; j--) {
            for (int k = sum+(N+M)*mina; k >= a[i]; k--) {
                if (dp[j-1][k-a[i]]) {
                    dp[j][k] = true;
                }
            }
        }
    }

    minAns = INF;
    maxAns = -INF;
    for (int i = 0; i <= sum+(N+M)*mina; i++) {
        if (dp[minNM][i]) {
            int temp = (i - mina*minNM) * (sum+mina*minNM-i);
            //cout << i << sum << temp << endl;
            maxAns = max(maxAns, temp);
            minAns = min(minAns, temp);
        }
    }
}

void output() {
    cout << maxAns << " " << minAns << endl;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> N >> M) {
        init();
        input();
        work();
        output();
    }
    return 0;
}
