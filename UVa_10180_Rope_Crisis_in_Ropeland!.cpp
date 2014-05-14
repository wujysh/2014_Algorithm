#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double eps = 1e-8;
int nCase;
double X1, Y1, X2, Y2, R, ans;

struct point {
    double x, y;
    point() {}
    point(int a, int b) : x{a}, y{b} {}
};

void init() {
    ans = 0;
}

void input() {
    cin >> X1 >> Y1 >> X2 >> Y2 >> R;
}

double calcDistance(double X1, double Y1, double X2, double Y2) {
    return sqrt((X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2));
}

// calculate square distance from line segment between v0 and v1 to point c
double DistanceSquared(point v0, point v1, point c) {
    double vx = v0.x - c.x;
    double vy = v0.y - c.y;
    double ux = v1.x - v0.x;
    double uy = v1.y - v0.y;

    double length = ux * ux + uy * uy;

    double det = (-vx * ux) + (-vy * uy);

    if (det < eps)
        return (v0.x - c.x) * (v0.x - c.x) + (v0.y - c.y) * (v0.y - c.y);
    if (det + eps > length)
        return (v1.x - c.x) * (v1.x - c.x) + (v1.y - c.y) * (v1.y - c.y);

    det = ux * vy - uy * vx;
    return (det * det) / length;
}

void work() {
    if (sqrt(DistanceSquared(point(X1, Y1), point(X2, Y2), point(0,0))) + eps > R) {
        ans = calcDistance(X1, Y1, X2, Y2);
    } else {
        double dist1 = calcDistance(X1, Y1, 0, 0);
        double dist2 = calcDistance(X2, Y2, 0, 0);
        double dist3 = calcDistance(X1, Y1, X2, Y2);
        ans += sqrt(dist1*dist1 - R*R);
        ans += sqrt(dist2*dist2 - R*R);

        double delta1 = acos(R / dist1);
        double delta2 = acos(R / dist2);
        double delta3 = acos((dist1*dist1 + dist2*dist2 - dist3*dist3) / (2*dist1*dist2));

        ans += R * (delta3-delta1-delta2);
    }
}

void output() {
    cout << fixed << setprecision(3) << ans << endl;
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
