#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 1010;
vector <string> line1, line2;
string str1, str2;
int nCase, dp[MAXN][MAXN];

void filter_and_divide(string &str, vector <string> &line) {
    for (int i = 0; i < str.length(); i++) {
        if (!isalpha(str[i]) && !isdigit(str[i])) {
            str[i] = ' ';
        }
    }
    stringstream ss(str);
    string word;
    while (ss >> word) {
        line.push_back(word);
    }
}

void init() {
    nCase++;
    line1.clear();
    line2.clear();
    memset(dp, 0, sizeof(dp));
    filter_and_divide(str1, line1);
    filter_and_divide(str2, line2);
}

void LCS() {
    for (int i = 1; i <= line1.size(); i++) {
        for (int j = 1; j <= line2.size(); j++) {
            if (line1[i-1] == line2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}

void output() {
    cout << setw(2) << nCase << ". ";
    if (str1 == "" || str2 == "") {
        cout << "Blank!" << endl;
    } else {
        cout << "Length of longest match: " << dp[line1.size()][line2.size()] << endl;
    }
}

int main() {
    while (getline(cin, str1)) {
        getline(cin, str2);
        init();
        LCS();
        output();
    }
    return 0;
}
