#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

const int MAXN = 100010;
const int INF = 0x3f3f3f3f;
int a[MAXN], nCase, cnt;
map <int, int> pre;
vector <int> dp;
stack <int> ans;

void init() {
    cnt = 0;
    pre.clear();
    dp.clear();
    dp.push_back(-INF);
}

void input() {
    string line;
    while (getline(cin, line) && line != "") {
        stringstream ss(line);
        ss >> a[cnt++];
    }
}

void work() {
    for (int i = 0; i < cnt; i++) {
        if (a[i] > dp.back()) {
            dp.push_back(a[i]);
            pre[a[i]] = (dp.size() - 2 < 0) ? -1 : dp[dp.size() - 2];
        } else {
            int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[pos] = a[i];
            pre[a[i]] = (pos - 1 < 0) ? -1 : dp[pos - 1];
        }
    }
}

void output() {
    cout << "Max hits: " << dp.size() - 1 << endl;
    int p = dp.back();
    while (p != -INF) {
        ans.push(p);
        p = pre[p];
    }
    while (!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }

    if (nCase) cout << endl;
}

int main() {
	cin >> nCase;
	cin.ignore(2);
	while (nCase--) {
		init();
		input();
		work();
		output();
    }
	return 0;
}
