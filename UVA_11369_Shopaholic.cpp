#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 20010;
int nCase, n, price[MAXN];
long long discount;

void init() {
    discount = 0;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
}

void work() {
    sort(price, price+n);
    for (int i = n-3; i >= 0; i -= 3) {
        discount += price[i];
    }
}

void output() {
    cout << discount << endl;
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
