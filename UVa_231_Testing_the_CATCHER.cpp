#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
vector <int> dp, a;
int cnt = 0, x;

void init() {
    cnt++;
    a.clear();
    dp.clear();
    dp.push_back(-INF);
}

void input() {
    a.push_back(x);
    while (cin >> x && x != -1) {
        a.push_back(x);
    }
}

void work() {
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > dp.back()) {
            dp.push_back(a[i]);
        } else {
            int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[pos] = a[i];
        }
    }
}

void output() {
    if (cnt > 1) cout << endl;
    cout << "Test #" << cnt << ":" << endl;
    cout << "  maximum possible interceptions: " << dp.size() - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
	while (cin >> x && x != -1) {
		init();
		input();
		work();
		output();
    }
	return 0;
}
