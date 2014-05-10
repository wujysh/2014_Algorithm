#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const double eps = 1e-8;
int N, n;
double ans, area[30];
bool attacked[30];

int cmp(double x) {
	if (fabs(x) < eps) return 0;
	if (x > 0) return 1;
	return -1;
}

struct point {
	double x, y;
	point() {}
	point(double a, double b) :x(a), y(b) {}
	friend point operator-(const point &a, const point &b) {
		return point(a.x - b.x, a.y - b.y);
	}
	friend bool operator==(const point &a, const point &b) {
		return cmp(a.x - b.x) == 0 && cmp(a.y - b.y) == 0;
	}
};
vector <point> a[30];

struct polygon_convex {
	vector <point> P;
	polygon_convex(int Size = 0) {
		P.resize(Size);
	}
} hull[30];

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

bool contain(const polygon_convex &a, const point &b) {
    int n = a.P.size();
    int sign = 0;
    for (int i = 0; i < n; i++) {
        int x = cmp(det(a.P[i]-b, a.P[(i+1)%n]-b));
        if (x) {
            if (sign) {
                if (sign != x) return false;
            } else sign = x;
        }
    }
    return true;
}

double calc_area(vector <point> a) {
    double sum = 0;
    a.push_back(a[0]);
    for (int i = 0; i < a.size()-1; i++) {
        sum += det(a[i], a[i+1]);
        //cout << det(a[i], a[i+1]) <<endl;
    }
    return sum / 2.0;
}

void init() {
    ans = 0;
    memset(attacked, false, sizeof(attacked));
}

void input() {
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        a[N].push_back(point(x, y));
    }
    hull[N] = convex_hull(a[N]);
    area[N] = calc_area(hull[N].P);
}

void work() {
    double x, y;
    while (cin >> x >> y) {
        for (int i = 0; i < N; i++) {
            if (!attacked[i]) {
                if (contain(hull[i], point(x, y))) {
                    ans += area[i];
                    attacked[i] = true;
                }
            }
        }
    }
}

void output() {
    cout << fixed << setprecision(2) << ans << endl;
}

int main() {
    init();
    while (cin >> n && n != -1) {
        input();
        N++;
    }
    work();
    output();
	return 0;
}
