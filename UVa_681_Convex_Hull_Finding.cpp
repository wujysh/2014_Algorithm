#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double eps = 1e-8;
int nCase, n;

int cmp(double x) {
	if (fabs(x) < eps) return 0;
	if (x > 0) return 1;
	return -1;
}

struct point {
	double x, y;
	point() {}
	point(double a, double b) :x(a), y(b) {}
	friend point operator - (const point &a, const point &b) {
		return point(a.x - b.x, a.y - b.y);
	}
	friend bool operator == (const point &a, const point &b) {
		return cmp(a.x - b.x) == 0 && cmp(a.y - b.y) == 0;
	}
};
vector <point> a;

double det(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}

struct polygon_convex {
	vector <point> P;
	polygon_convex(int Size = 0) {
		P.resize(Size);
	}
} ans;

bool comp_less(const point &a, const point &b) {
	return cmp(a.y - b.y < 0) || cmp(a.y - b.y) == 0 && cmp(a.x - b.x) < 0;
}

polygon_convex convex_hull(vector <point> a) {
	polygon_convex res(2 * a.size() + 5);
	sort(a.begin(), a.end(), comp_less);
	a.erase(unique(a.begin(), a.end()), a.end());
	int m = 0;
	for (int i = 0; i < a.size(); i++) {
		while (m > 1 && cmp(det(res.P[m - 1] - res.P[m - 2], a[i] - res.P[m - 2])) <= 0) --m;
		res.P[m++] = a[i];
	}
	int k = m;
	for (int i = int(a.size()) - 2; i >= 0; i--) {
		while (m > k && cmp(det(res.P[m - 1] - res.P[m - 2], a[i] - res.P[m - 2])) <= 0) --m;
		res.P[m++] = a[i];
	}
	res.P.resize(m);
	if (a.size() > 1) res.P.resize(m - 1);
	return res;
}

void init() {
    a.clear();
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        a.push_back(point(x, y));
    }
}

void work() {
    ans = convex_hull(a);
}

void output() {
    cout << ans.P.size() + 1 << endl;
    for (int i = 0; i < ans.P.size(); i++) {
        cout << ans.P[i].x << " " << ans.P[i].y << endl;
    }
    cout << ans.P[0].x << " " << ans.P[0].y << endl;

    if (nCase) {  // cout << -1 << endl;
        cin >> n;
        cout << n << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin >> nCase;
	cout << nCase << endl;
	while (nCase--) {
		init();
		input();
		work();
		output();
	}
	return 0;
}

