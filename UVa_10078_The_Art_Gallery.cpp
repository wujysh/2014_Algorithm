#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const double eps = 1e-8;
int n;

int cmp(double x) {
	if (fabs(x) < eps) return 0;
	if (x > 0) return 1;
	return -1;
}

struct point {
	double x, y;
	point() {}
	point(double a, double b) : x(a), y(b) {}
	friend point operator + (const point &a, const point &b) {
        return point(a.x + b.x, a.y + b.y);
	}
	friend point operator - (const point &a, const point &b) {
		return point(a.x - b.x, a.y - b.y);
	}
	friend bool operator == (const point &a, const point &b) {
		return cmp(a.x - b.x) == 0 && cmp(a.y - b.y) == 0;
	}
	friend point operator * (const point &a, const double &b) {
		return point(a.x * b, a.y * b);
	}
	friend point operator * (const double &a, const point &b) {
        return point(a * b.x, a * b.y);
	}
	friend point operator / (const point &a, const double &b) {
		return point(a.x / b, a.y / b);
	}
};
vector <point> a;

struct polygon_convex {
	vector <point> P;
	polygon_convex(int Size = 0) {
		P.resize(Size);
	}
} hull;

double det(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}

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
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        a.push_back(point(x, y));
    }
}

void work() {
    hull = convex_hull(a);
}

void output() {
    if (hull.P.size() != a.size()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
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
