#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110;
string str1, str2;
int nCase, dp[MAXN][MAXN];

void init() {
    nCase++;
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
    cout << "Case #" << nCase << ": you can visit at most " << dp[str1.length()][str2.length()] << " cities." << endl;
}

int main() {
    while (getline(cin, str1) && str1 != "#") {
        getline(cin, str2);
        init();
        LCS();
        output();
    }
    return 0;
}
