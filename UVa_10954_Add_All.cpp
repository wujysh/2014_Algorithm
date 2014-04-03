#include <iostream>
#include <queue>
using namespace std;

priority_queue <int> q;
int n, sum;

void init() {
    sum = 0;
    while (!q.empty()) q.pop();
}

void input() {
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(-x);
    }
}

void work() {
    while (q.size() >= 2) {
        int x, y;
        x = -q.top();
        q.pop();
        y = -q.top();
        q.pop();
        q.push(-(x + y));
        sum += x + y;
    }
}

void output() {
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
	while (cin >> n && n) {
		init();
		input();
		work();
		output();
	}
	return 0;
}
