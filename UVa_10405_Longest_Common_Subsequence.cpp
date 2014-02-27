#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

string str1, str2;
int dp[MAXN][MAXN];

void init() {
    str1.clear();
    str2.clear();
    memset(dp, 0, sizeof(dp));
}

void LCS() {
    for (int i = 1; i <= str1.length(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}

void output() {
    cout << dp[str1.length()][str2.length()] << endl;
}

int main() {
    init();
    while (getline(cin, str1)) {
        getline(cin, str2);
        LCS();
        output();
        init();
    }
    return 0;
}
