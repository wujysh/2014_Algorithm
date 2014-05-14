#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const double PI = acos(-1);
const string DIR[] = {"N", "NbE", "NNE", "NEbN", "NE", "NEbE", "ENE", "EbN",
                       "E", "EbS", "ESE", "SEbE", "SE", "SEbS", "SSE", "SbE",
                       "S", "SbW", "SSW", "SWbS", "SW", "SWbW", "WSW", "WbS",
                       "W", "WbN", "WNW", "NWbW", "NW", "NWbN", "NNW", "NbW"};

map <string, double> mp;
int n;
double off, ans;

struct point {
    double x, y;
    point(double x0 = 0, double y0 = 0) {
        x = x0;
        y = y0;
    }
    double getdis(point p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};

struct dir { //方向
    double a, dis; //a为角度，dis为偏移距离
    dir(double a0 = 0, double dis0 = 0) {
        a = a0;
        dis = dis0;
    }
};
vector <dir> v;

double dot(point p0, point p1, point p2) { //p0p1点乘 p0p2;
    return (p1.x - p0.x) * (p2.x - p0.x) + (p1.y - p0.y) * (p2.y - p0.y);
}

struct line {
    point a, b;
    line(point a0, point b0) {
        a = a0;
        b = b0;
    }
    double getdis(point p) { //点到线段的最小距离
        if (dot(a, p, b) < 0 || dot(b, p, a) < 0) return min(p.getdis(a), p.getdis(b));
        else {
            double a0, b0, c0;
            a0 = a.y - b.y;
            b0 = b.x - a.x;
            c0 = a.x * b.y - b.x * a.y;
            return fabs(a0 * p.x + b0 * p.y + c0) / sqrt(a0 * a0 + b0 * b0);
        }
    }
};

void calcDegree() {
    for (int i = 0; i < 32; i++) {
        mp[DIR[i]] = PI * double(i) / double(16);
    }
}

void init() {
    v.clear();
}

void input() {
    string st0;
    double dis0;
    for (int i = 0; i < n; i++) {
        cin >> st0 >> dis0;
        v.push_back(dir(mp[st0], dis0));
    }
    cin >> off;
}

void work() {
    point d(0, 0), t(0, 0), pre;
    for (int i = 0; i < n; i++) { //算出宝藏的真正点 终点d
        d.x += cos(v[i].a) * v[i].dis;
        d.y += sin(v[i].a) * v[i].dis;
    }
    ans = d.getdis(t);
    for (int i = 0; i < n; i++) { //算出实际寻宝每次的路线为 line l(pre,t);
        pre = t;
        t.x += cos(v[i].a - off * PI / double(180)) * v[i].dis;
        t.y += sin(v[i].a - off * PI / double(180)) * v[i].dis;
        line l(pre, t);
        ans = min(ans, l.getdis(d)); //求出路线 line l 距离宝藏点d距离
    }
}

void output() {
    cout << fixed << setprecision(2) << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    calcDegree();
    while (cin >> n && n) {
        init();
        input();
        work();
        output();
    }
    return 0;
}
