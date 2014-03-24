#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 10010;
bool r[MAXN], nr[MAXN]; // remain value
int num[MAXN], n, k, nCase;

void init() {
    memset(num, 0, sizeof(num));
    memset(r, 0, sizeof(r));
}

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
}

void work() {
    int x = num[0] % k;
    if (x < 0) x += k;
    r[x] = true;
    for (int i = 1; i < n; i++) {
        memset(nr, 0, sizeof(nr));
        for (int v = 0; v < 100; v++) {
            if (r[v]) {
                int m1 = (v + num[i]) % k;
                if (m1 < 0) m1 += k;
                int m2 = (v - num[i]) % k;
                if (m2 < 0) m2 += k;
                nr[m1] = true;
                nr[m2] = true;
            }
        }
        memcpy(r, nr, sizeof(r));
    }
}

void output() {
	if (r[0]) {
        cout << "Divisible" << endl;
    } else {
        cout << "Not divisible" << endl;
    }
}

int main() {
	cin >> nCase;
	while (nCase--) {
		init();
		input();
		work();
		output();
    }
	return 0;
}
