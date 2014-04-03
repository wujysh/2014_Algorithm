#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x7fffffff;
vector <int> dp1, dp2, a, front, back;
int n, ans;

void init() {
    a.resize(n);
    dp1.clear();
    dp1.push_back(-INF);
    front.resize(n);
    dp2.clear();
    dp2.push_back(-INF);
    back.resize(n);
    ans = 1;
}

void input() {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void work() {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > dp1.back()) {
            dp1.push_back(a[i]);
            front[i] = dp1.size()-1;
        } else {
            vector <int>::iterator it = lower_bound(dp1.begin(), dp1.end(), a[i]);
            *it = a[i];
            front[i] = it - dp1.begin();
        }
    }

    for (int i = a.size()-1; i >= 0; i--) {
        if (a[i] > dp2.back()) {
            dp2.push_back(a[i]);
            back[i] = dp2.size() -1;
        } else {
            vector <int>::iterator it = lower_bound(dp2.begin(), dp2.end(), a[i]);
            *it = a[i];
            back[i] = it - dp2.begin();
        }
    }
}

void output() {
    for (int i = 0; i < n; i++) {
        if (min(front[i], back[i]) * 2 - 1 > ans)
            ans = min(front[i], back[i]) * 2 - 1;
    }
    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		init();
		input();
		work();
		output();
    }
	return 0;
}
