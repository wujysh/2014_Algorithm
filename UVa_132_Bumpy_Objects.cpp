#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

const int INF = 0x3f3f3f3f;
int mass_centerX, mass_centerY, x, y, index, ans;
string ID;

struct point {
    int x, y, index;
    point() {}
    point(int a, int b, int c) : x{a}, y{b}, index{c} {}
    bool operator < (point X) const {
        return x < X.x;
    }
} mass_center;
vector <point> P, H;

int det(point A, point B, point C) {
    return A.x * B.y + B.x * C.y + C.x * A.y - A.y * B.x - B.y * C.x - C.y * A.x;
}

vector <point> Convex_Hull(vector <point> &P) {
    vector <point> H(2 * P.size()+5);
    sort(P.begin(), P.end());
    int k = 0;
    for (int i = 0; i < P.size(); i++) {
        while (k >= 2 && det(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    int t = k;
    for (int i = P.size() - 1; i >= 0; i--) {
        while (k > t && det(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k);
    return H;
}

bool base_line(point mass_center, point A, point B) {
    if (det(A, B, mass_center) <= 0) return false;
    if ((mass_center.x - A.x) * (B.x - A.x) + (mass_center.y - A.y) * (B.y - A.y) < 0) return false;
    if ((mass_center.x - B.x) * (A.x - B.x) + (mass_center.y - B.y) * (A.y - B.y) < 0) return false;
    return true;
}

void init() {
    index = 1;
    P.clear();
    ans = INF;
}

void input() {
    cin >> mass_centerX >> mass_centerY;
    mass_center = point(mass_centerX, mass_centerY, 0);
    while (cin >> x >> y && (x || y)) {
        P.push_back(point(x, y, index));
        index++;
    }
}

void work() {
    H = Convex_Hull(P);
    for (int i = 0; i < H.size() - 1; i++) {
        if (base_line(mass_center, H[i], H[i + 1])) {
            ans = min(ans, max(H[i].index, H[i + 1].index));
        }
    }
}

void output() {
    cout << setw(21) << setiosflags(ios::left) << ID << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> ID && ID != "#") {
        init();
        input();
        work();
        output();
    }
    return 0;
}
