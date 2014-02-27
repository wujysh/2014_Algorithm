#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 110;
int nCase, N1, N2, a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

void init() {
    nCase++;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(dp, 0, sizeof(dp));
}

void input() {
    for (int i = 0; i < N1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N2; i++) {
        cin >> b[i];
    }
}

void LCS() {
    for (int i = 1; i <= N1; i++) {
        for (int j = 1; j <= N2; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}

void output() {
    cout << "Twin Towers #" << nCase << endl;
    cout << "Number of Tiles : " << dp[N1][N2] << endl;
    cout << endl;
}

int main() {
    while (cin >> N1 >> N2 && (N1 || N2)) {
        init();
        input();
        LCS();
        output();
    }
    return 0;
}
