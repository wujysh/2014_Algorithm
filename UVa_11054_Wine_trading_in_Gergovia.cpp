#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 100010;
int a[MAXN], n;
long long ans;

void init() {
    ans = 0;
}

void input() {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void work1() {  // AC (0.052s)
    for (int i = 0; i < n-1; i++) {
        a[i+1] += a[i];
        ans += abs(a[i]);
    }
}

void work() {  // TLE (AC in Monthly Match 1)
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        for (int j = i+1; j < n; j++) {
            if (a[i] > 0 && a[j] < 0 || a[i] < 0 && a[j] > 0) {
                int absi = abs(a[i]);
                int absj = abs(a[j]);
                int min = absi < absj ? absi: absj;
                if (a[i] > 0) a[i] -= min;
                else a[i] += min;
                if (a[j] > 0) a[j] -= min;
                else a[j] += min;
                ans += (j-i) * min;
            }
            if (a[i] == 0) break;
        }
    }
}

void work2() {  // AC (2.336s)
    int i = 0;
    while (i < n) {
        if (a[i] < 0) {
            for (int j = i + 1 ; j < n ; j++) {
                if (a[j] > 0) {
                    if (abs(a[i]) > abs(a[j])) {
                        ans += abs(a[j]) * (j - i);
                        a[i] += a[j] ;
                        a[j] = 0;
                    } else {
                        ans += abs(a[i]) * (j - i);
                        a[j] += a[i] ;
                        a[i] = 0;
                    }
                    break;
                }
            }
        } else if (a[i] > 0) {
            for (int j = i + 1 ; j < n ; j++) {
                if (a[j] < 0) {
                    if (abs(a[i]) > abs(a[j])) {
                        ans += abs(a[j]) * (j - i);
                        a[i] += a[j] ;
                        a[j] = 0;
                    } else {
                        ans += abs(a[i]) * (j - i);
                        a[j] += a[i] ;
                        a[i] = 0;
                    }
                    break;
                }
            }
        }
        if (!a[i]) i++;
    }
}

void output() {
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n && n) {
        init();
        input();
        work2();
        //work1();
        //work();
        output();
    }
    return 0;
}
