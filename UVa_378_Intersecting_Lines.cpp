#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int nCase;
double ansX, ansY;

struct Line {
	long long x1, y1, x2, y2, u, v;
	Line(long long x10 = 0, long long y10 = 0, long long x20 = 0, long long y20 = 0) {
		x1 = x10;  y1 = y10;  x2 = x20;  y2 = y20;
		u = x2 - x1;  v = y2 - y1;
	}
} line1, line2;

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
	if (!cross(l3, l1) && !cross(l1, l4)) return true;
	if (!cross(l5, l2) && !cross(l2, l6)) return true;
	return false;
}

int judge(Line l1, Line l2) {
	if (cross(l1, l2) == 0) {  // 平行
		if (furtherTest(l1, l2)) {  // 重合（平行又相交）
			return 2;
		}
		return 3;
	} else {  // 不平行（直线、一定相交）
		double k1 = (double)(l1.y2 - l1.y1) / (l1.x2 - l1.x1);
		double k2 = (double)(l2.y2 - l2.y1) / (l2.x2 - l2.x1);

		if (l1.x2 - l1.x1 == 0) ansX = l1.x1;  // 斜率不存在
		else if (l2.x2 - l2.x1 == 0) ansX = l2.x1;
		else ansX = (k1*l1.x1 - k2*l2.x1 - l1.y1 + l2.y1) / (k1 - k2);

		if (l1.y2 - l1.y1 == 0) ansY = l1.y1;
		else if (l2.y2 - l2.y1 == 0) ansY = l2.y1;
		else ansY = k1*(ansX - l1.x1) + l1.y1;

		return 1;
	}
}

void input() {
    long long x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    line1 = Line(x1, y1, x2, y2);
    line2 = Line(x3, y3, x4, y4);
}

void output() {
    int response = judge(line1, line2);
    if (response == 1) {
        cout << "POINT ";
        cout << setprecision(2) << fixed << ansX << " " << ansY << endl;
    } else if (response == 2) {
        cout << "LINE" << endl;
    } else if (response == 3) {
        cout << "NONE" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin >> nCase;
	cout << "INTERSECTING LINES OUTPUT" << endl;
	while (nCase--) {
		input();
		output();
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
