#include <iostream>
#include <algorithm>
using namespace std;

int nCase, n, ans;

struct Line {
	long long x1, y1, x2, y2, u, v;
	Line(long long x10 = 0, long long y10 = 0, long long x20 = 0, long long y20 = 0) {
		x1 = x10;  y1 = y10;  x2 = x20;  y2 = y20;
		u = x2 - x1;  v = y2 - y1;
	}
};
Line line[110];

long long cross(Line l1, Line l2) {
	return(l1.u*l2.v - l2.u*l1.v);
}

bool fastTest(Line l1, Line l2) {
	long long left1 = min(l1.x1, l1.x2), left2 = min(l2.x1, l2.x2);
	long long right1 = max(l1.x1, l1.x2), right2 = max(l2.x1, l2.x2);
	long long top1 = max(l1.y1, l1.y2), top2 = max(l2.y1, l2.y2);
	long long bottom1 = min(l1.y1, l1.y2), bottom2 = min(l2.y1, l2.y2);
	if (right1 < left2 || left1 > right2 || top1 < bottom2 || bottom1 > top2) return true;
	return false;
}

bool furtherTest(Line l1, Line l2) {  // l1:AB  l2:CD
	Line l3 = Line(l1.x1, l1.y1, l2.x1, l2.y1);  // l3:AC
	Line l4 = Line(l1.x1, l1.y1, l2.x2, l2.y2);  // l4:AD
	Line l5 = Line(l2.x1, l2.y1, l1.x1, l1.y1);  // l5:CA
	Line l6 = Line(l2.x1, l2.y1, l1.x2, l1.y2);  // l6:CB
	if (cross(l3, l1)*cross(l1, l4) >= 0 && cross(l5, l2)*cross(l2, l6) >= 0) return false;
	return true;
}

bool judge(Line l1, Line l2) {
	if (!fastTest(l1, l2)) {
		if (!furtherTest(l1, l2)) {
			return false;
		}
	}
	return true;
}

void init() {
    ans = 0;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        line[i] = Line(x1, y1, x2, y2);
    }
}

void work() {
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (i != j && !judge(line[i], line[j])) {
                flag = true;
                break;
            }
        }
        if (!flag) ans++;
    }
}

void output() {
    cout << ans << endl;
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
