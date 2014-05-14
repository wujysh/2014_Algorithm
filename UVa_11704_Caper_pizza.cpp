#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1);

int c, p;
bool ans;

struct point {
    double x, y, angle;
    int type;  // 0-caper; 1-peppercorn
    point() {}
    point(double x0, double y0, int t0) : x(x0), y(y0), angle(atan2(y0, x0)), type(t0) {}
    bool operator<(const point &b) const {
        return angle < b.angle;
    }
};
vector<point> points;

int cmp(double x) {
    if (fabs(x) < EPS) return 0;
    if (x > 0) return 1;
    return -1;
}

void init() {
    points.clear();
    ans = false;
}

void input() {
    double x, y;
    for (int i = 0; i < c; i++) {
        cin >> x >> y;
        points.push_back(point(x, y, 0));
    }
    for (int j = 0; j < p; j++) {
        cin >> x >> y;
        points.push_back(point(x, y, 1));
    }
}

void work() {
    sort(points.begin(), points.end());

    int nextpoint = 1, cnt[2] = {0};
    cnt[points[0].type]++;
    for (int i = 0; i < c + p; i++) {
        points.push_back(points[i]);
        points[i + c + p].angle += 2 * PI;
    }

    for (int i = 0; i < c + p; i++) {
        while (cmp(fabs(points[nextpoint].angle - points[i].angle) - PI) <= 0) {
            cnt[points[nextpoint].type]++;
            nextpoint++;
        }
        if (2 * cnt[0] == c && 2 * cnt[1] == p) {
            ans = true;
            return;
        }
        cnt[points[i].type]--;
    }
}

void output() {
    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> c >> p && !(c == -1 && p == -1)) {
        init();
        input();
        work();
        output();
    }
    return 0;
}
