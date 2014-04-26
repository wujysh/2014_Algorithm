#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 10010;
int k, n, minLeft, maxRight, ans, nCase;
bool billboard[MAXN * 2];

struct node {
	int l, r;
	node(int l1, int r1) {
		l = l1;  r = r1;
	}
	friend bool operator < (node a, node b) {
		return a.r < b.r;
	}
};
vector <node> jogger;

void init() {
    ans = minLeft = maxRight = 0;
    memset(billboard, false, sizeof(billboard));
    jogger.clear();
}

void input() {
    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (a < minLeft) minLeft = a;
        if (b > maxRight) maxRight = b;
        jogger.push_back(node(a, b));
    }
}

void work() {
    sort(jogger.begin(), jogger.end());

    for (int i = 0; i < jogger.size(); i++) {
        int cnt = 0;
        for (int j = jogger[i].l; j <= jogger[i].r; j++) {
            if (billboard[j + MAXN]) {
                cnt++;
            }
        }
        if (cnt >= k || (jogger[i].r - jogger[i].l < k && cnt - 1 == jogger[i].r - jogger[i].l)) continue;
        for (int j = jogger[i].r; cnt < k && j >= jogger[i].l; j--) {
            if (!billboard[j + MAXN]) {
                billboard[j + MAXN] = true;
                ans++;  cnt++;
            }
        }
    }
}

void output() {
    cout << ans << endl;
    for (int i = minLeft; i <= maxRight; i++) {
        if (billboard[i + MAXN]) {
            cout << i << endl;
        }
    }
    if (nCase) cout << endl;
}

int main() {
	cin >> nCase;
	while (nCase--) {
        init();
        input();
        work();
        output();
	}
	return 0;
}
