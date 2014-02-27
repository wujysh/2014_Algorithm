#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 110;
int dp[MAXN][MAXN], cnt;
vector <string> text1, text2;
string line, word;

void init() {
    cnt = 0;
    text1.clear();
    text2.clear();
    memset(dp, 0, sizeof(dp));
}

void input() {
    do {
        stringstream ss(line);
        while (ss >> word) {
            text1.push_back(word);
        }
    } while (getline(cin, line) && line != "#");

    while (getline(cin, line) && line != "#") {
        stringstream ss(line);
        while (ss >> word) {
            text2.push_back(word);
        }
    }
}

void LCS() {
    for (int i = 1; i <= text1.size(); i++) {
        for (int j = 1; j <= text2.size(); j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
}

void backtrack(int i, int j) {
    if (i == 0 || j == 0) return;

    if (text1[i-1] == text2[j-1]) {
        backtrack(i-1, j-1);
        if (++cnt > 1) cout << " ";
        cout << text1[i-1];
    } else {
        if (dp[i][j-1] > dp[i-1][j]) {
            backtrack(i, j-1);
        } else {
            backtrack(i-1, j);
        }
    }
}

void output() {
    backtrack(text1.size(), text2.size());
    cout << endl;
}

int main() {
    while (getline(cin, line)) {
        init();
        input();
        LCS();
        output();
    }
    return 0;
}
