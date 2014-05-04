#include <iostream>
#include <algorithm>
using namespace std;

int nCase;

struct Line {
	int x1, y1, x2, y2, u, v;
	Line(int x10 = 0, int y10 = 0, int x20 = 0, int y20 = 0) {
		x1 = x10;  y1 = y10;  x2 = x20;  y2 = y20;
		u = x2 - x1;  v = y2 - y1;
	}
};
Line rectangle[4], line;

int cross(Line l1, Line l2) {
	return(l1.u*l2.v - l2.u*l1.v);
}

bool fastTest(Line l1, Line l2) {
	int left1 = min(l1.x1, l1.x2), left2 = min(l2.x1, l2.x2);
	int right1 = max(l1.x1, l1.x2), right2 = max(l2.x1, l2.x2);
	int top1 = max(l1.y1, l1.y2), top2 = max(l2.y1, l2.y2);
	int bottom1 = min(l1.y1, l1.y2), bottom2 = min(l2.y1, l2.y2);
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

bool judge() {
	// line in rectangle
	if (line.x1 >= rectangle[0].x1 && line.x1 <= rectangle[1].x1 &&
		line.x2 >= rectangle[0].x1 && line.x2 <= rectangle[1].x1 &&
		line.y1 >= rectangle[3].y1 && line.y1 <= rectangle[2].y1 &&
		line.y2 >= rectangle[3].y1 && line.y2 <= rectangle[2].y1) return false;

	// fast test
	for (int i = 0; i < 4; i++) {
		if (!fastTest(line, rectangle[i])) {
			// further test
			if (!furtherTest(line, rectangle[i])) {
				return false;
			}
		}
	}
	return true;
}


void input() {
    int xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
    cin >> xstart >> ystart >> xend >> yend >> xleft >> ytop >> xright >> ybottom;

    if (xright < xleft) swap(xleft, xright);
    if (ybottom > ytop) swap(ybottom, ytop);

    line = Line(xstart, ystart, xend, yend);
    rectangle[0] = Line(xleft, ytop, xleft, ybottom);
    rectangle[1] = Line(xright, ytop, xright, ybottom);
    rectangle[2] = Line(xleft, ytop, xright, ytop);
    rectangle[3] = Line(xleft, ybottom, xright, ybottom);
}

void output() {
    if (judge()) {
        cout << "F" << endl;
    } else {
        cout << "T" << endl;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin >> nCase;
	while (nCase--) {
        input();
        output();
	}
	return 0;
}
