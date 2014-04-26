#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, nCase;

struct node {
	int order, t, s;
	node(int o1, int t1, int s1) {
		order = o1;  t = t1;  s = s1;
	}
	friend bool operator < (node a, node b) {
		return a.t * b.s < b.t * a.s;
	}
};
vector <node> job;

void init() {
    job.clear();
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t, s;
        cin >> t >> s;
        job.push_back(node(i, t, s));
    }
}

void work() {
    sort(job.begin(), job.end());
}

void output() {
    for (int i = 0; i < job.size(); i++) {
        if (i) cout << " ";
        cout << job[i].order;
    }
    cout << endl;
    if (nCase) cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
	cin >> nCase;
	while (nCase--) {
		init();
		input();
		work();
		output();
	}
	return 0;
}
