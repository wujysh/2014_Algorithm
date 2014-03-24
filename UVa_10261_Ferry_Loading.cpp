#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 2010, MAXM = 10010;
bool dp[MAXN][MAXM], ans[MAXN];
long long len[MAXN], sum[MAXN], pre[MAXN][MAXM];
long long ferryLen, n, maxCar, nCase, tail;

void init() {
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    n = 0;
    sum[0] = 0;
}

void input() {
    cin >> ferryLen;
    ferryLen *= 100;
    int k;
    while (cin >> k && k) {
        n++;
        len[n] = k;
        sum[n] = sum[n-1] + k;
    }
}

void work() {
    tail = -1;
    for (int i = 1; i <= n; i++) {
        for (int v = 0; v <= ferryLen; v++) {
            if (v >= len[i] && dp[i-1][v-len[i]]) {
                maxCar = i;
                tail = v;
                dp[i][v] = true;
                pre[i][v] = v - len[i];
            } else if (sum[i]-v <= ferryLen && dp[i-1][v]) {
                maxCar = i;
                tail = v;
                dp[i][v] = true;
                pre[i][v] = v;
            }
        }
    }
    for (int i = maxCar; i >= 1; i--) {
        int v = pre[i][tail];
        if (v == tail) {
            ans[i] = true;
        } else {
            ans[i] = false;
        }
        tail = v;
    }
}

void output() {
    cout << maxCar << endl;
    for (int i = 1; i <= maxCar; i++) {
        if (ans[i]) {
            cout << "starboard" << endl;
        } else {
            cout << "port" << endl;
        }
    }
    if (nCase) cout << endl;
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

/*

*/
