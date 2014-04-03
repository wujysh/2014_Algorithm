#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

const int INF = 0x7fffffff;
vector <int> dp, a, pre, numPos;
stack <int> ans;
int x;

void init() {
	pre.clear();
	numPos.clear();
	numPos.push_back(0);
	dp.clear();
	dp.push_back(-INF);
}

void input() {
    while (cin >> x) {
		a.push_back(x);
		pre.push_back(-1);
	}

}

void work() {
    for (int i = 0; i < a.size(); i++) {
		if (a[i] > dp.back()) {
			pre[i] = numPos.back();
			dp.push_back(a[i]);
			numPos.push_back(i);
		} else {
			vector <int>::iterator it = lower_bound(dp.begin(), dp.end(), a[i]);
			*it = a[i];
			numPos[it - dp.begin()] = i;
			pre[i] = numPos[it - dp.begin() - 1];
		}
	}
}

void output() {
    cout << dp.size() - 1 << endl << "-" << endl;
	int p = numPos[dp.size() - 1];
	for (int i = 0; i < dp.size() - 1; i++) {
		ans.push(a[p]);
		p = pre[p];
	}
	while (!ans.empty()) {
		cout << ans.top() << endl;
		ans.pop();
	}
}

int main() {
    init();
    input();
    work();
    output();
	return 0;
}
