#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

const double eps = 1e-8;

int cmp(double x) {
	if (fabs(x) < eps) return 0;
	if (x > 0) return 1;
	return -1;
}

inline double sqr(double x) {
	return x * x;
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
	double norm() {
		return sqrt(sqr(x) + sqr(y));
	}
};

double det(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}

struct polygon_convex {
	vector <point> P;
	polygon_convex(int Size = 0) {
		P.resize(Size);
	}
};

point pivot;
bool cmp_clockwise(const point &a, const point &b) {
	double t = det(a - pivot, b - pivot);
	return cmp(t) > 0 || (cmp(t) == 0 && cmp((pivot - a).norm() - (pivot - b).norm()) < 0);
}

polygon_convex convex_hull(vector <point> a) {
	polygon_convex res(2 * a.size() + 5);

	int index = 0;
	for (int i = 1; i < a.size(); i++) {
		if (a[i].x < a[index].x || (a[i].x == a[index].x && a[i].y < a[index].y)) {
			index = i;
		}
	}
	pivot = a[index];
	swap(a[0], a[index]);

	sort(a.begin(), a.end(), cmp_clockwise);
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

int main() {
	//freopen("output.txt", "w", stdout);
	int n, nCase = 0;
	while (cin >> n && n) {
		nCase++;

		vector <point> a;
		a.clear();
		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			a.push_back(point(x, y));
		}

		polygon_convex ans = convex_hull(a);
		//sort(ans.P.begin(), ans.P.end(), cmp_clockwise);
		reverse(ans.P.begin(), ans.P.end());

		cout << "Region #" << nCase << ":" << endl;
		cout << setprecision(1) << fixed;
		for (int i = 0; i < ans.P.size(); i++) {
			cout << "(" << ans.P[i].x << "," << ans.P[i].y << ")-";
		}
		cout << "(" << ans.P[0].x << "," << ans.P[0].y << ")" << endl;

		ans.P.push_back(ans.P[0]);
		double perimeter = 0;
		for (int i = 0; i < ans.P.size() - 1; i++) {
			perimeter += (ans.P[i + 1] - ans.P[i]).norm();
		}
		cout << setprecision(2) << fixed;
		cout << "Perimeter length = " << perimeter << endl;
		if (nCase > 1) cout << endl;
	}
	return 0;
}
