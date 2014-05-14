#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

const double PI = acos(-1);
const double EPS = 1e-8;
const double INF = 1 << 20;

int R, h;
double ans_max, ans_min;

int cmp(double x) {
	if (fabs(x) < EPS) return 0;
	if (x > 0) return 1;
	return -1;
}
inline double sqr(double x) {
	return x * x;
}
double mysqrt(double n) {
    return sqrt(max(0.0, n));
}

struct point {
	double x, y;
	point() {}
	point(double a, double b) :x(a), y(b) {}
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
	double norm() {
		return sqrt(sqr(x) + sqr(y));
	}
} point1, point2, point3, point4;

double det(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}
double dot(const point &a, const point &b) {
	return a.x * b.x + a.y * b.y;
}

void circle_cross_line(point a, point b, point o, double r, point ret[], int &num) {
    double x0 = o.x, y0 = o.y;
    double x1 = a.x, y1 = a.y;
    double x2 = b.x, y2 = b.y;
    double dx = x2 - x1, dy = y2 - y1;
    double A = dx*dx + dy*dy;
    double B = 2*dx*(x1 - x0) + 2*dy*(y1 - y0);
    double C = sqr(x1 - x0) + sqr(y1 - y0) - sqr(r);
    double delta = B*B - 4*A*C;
    num = 0;
    if (cmp(delta) >= 0) {
        double t1 = (-B - mysqrt(delta)) / (2*A);
        double t2 = (-B + mysqrt(delta)) / (2*A);
        //if (cmp(t1 - 1) <= 0 && cmp(t1) >= 0) {
            ret[num++] = point(x1 + t1*dx, y1 + t1*dy);
        //}
        //if (cmp(t2 - 1) <= 0 && cmp(t2) >= 0) {
            ret[num++] = point(x1 + t2*dx, y1 + t2*dy);
        //}
    }
}

struct line {
	point a, b;
	line() {}
	line(point x, point y) :a(x), b(y) {}
};

bool parallel(line a, line b) {
	return !cmp(det(a.a - a.b, b.a - b.b));
}
bool line_make_point(line a, line b, point &res) {
	if (parallel(a, b)) return false;
	double s1 = det(a.a - b.a, b.b - b.a);
	double s2 = det(a.b - b.a, b.b - b.a);
	res = (s1 * a.b - s2 * a.a) / (s1 - s2);
	return true;
}

bool isCrossed(line l1, line l2) {
    if (det(l2.a - l1.a, l1.b - l1.a) * det(l2.b - l1.a, l1.b - l1.a) < 0) {
        return true;
    } else {
        return false;
    }
}

void init() {
    ans_max = -INF;
    ans_min = INF;
}

void input() {
    cin >> point1.x >> point1.y >> point2.x >> point2.y;
    cin >> point3.x >> point3.y >> point4.x >> point4.y;
}

void work() {
    int num;
    point ret1[5], ret2[5], points[5], o(0, 0);
    circle_cross_line(point1, point2, o, R, ret1, num);
    circle_cross_line(point3, point4, o, R, ret2, num);
    points[0] = ret1[0];    points[1] = ret2[0];
    points[2] = ret1[1];    points[3] = ret2[1];
    line_make_point(line(point1, point2), line(point3, point4), points[4]);

    //for (int i = 0; i < 5; i++) {
    //    cout << points[i].x << " " << points[i].y << endl;
    //}

    for (int i = 0; i < 4; i++) {
        double a, b, c;
        a = (points[i] - o).norm();
        b = (points[(i+1) % 4] - o).norm();
        c = (points[i] - points[(i+1) % 4]).norm();

        double angle = acos((sqr(a) + sqr(b) - sqr(c)) / (2 * a * b));

        double area, area1, area2, area3, area4;
        //cout << (points[i] - points[4]).x << " " << (points[i] - points[4]).y << " ";
        //cout << (points[(i+1) % 4] - points[4]).x << " " << (points[(i+1) % 4] - points[4]).y << endl;
        area1 = fabs(0.5 * det(points[i] - points[4], points[(i+1) % 4] - points[4]));
        area3 = fabs(0.5 * det(points[i] - o, points[(i+1) % 4] - o));
        //cout << area1 << " " << area3 << endl;
        line line1(points[i], points[(i+1) % 4]), line2(o, points[4]);
        if (!isCrossed(line1, line2)) {
            //cout << "Not Crossed" << endl;
            area4 = 0.5 * angle * sqr(R);
            area2 = area4 - area3;
        } else {
            //cout << "Crossed" << endl;
            if (cmp((sqr(a) + sqr(b) - sqr(c)) / (2 * a * b)) < 0) {
                angle = 2 * PI - angle;
            }
            area4 = 0.5 * angle * sqr(R);
            area2 = area4 + area3;
        }

        area = area1 + area2;
        ans_max = max(ans_max, area);
        ans_min = min(ans_min, area);
        //cout << area << endl;
    }
}

void output() {
    cout << fixed << setprecision(2) << ans_max*h << " " << ans_min*h << endl;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> R >> h) {
        init();
        input();
        work();
        output();
    }
    return 0;
}
