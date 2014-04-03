#include <iostream>
using namespace std;

int nCase, s, n, maxlen, minlen;

void init() {
    maxlen = 0, minlen = 0;
}

void work() {
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x = (x < (s - x)) ? x : (s - x);
        if (x > minlen) {
            minlen = x;
        }
        if (s - x > maxlen) {
            maxlen = s - x;
        }
    }
}

void output() {
    cout << minlen << " " << maxlen << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> nCase;
	while (nCase--) {
		init();
		work();
		output();
    }
	return 0;
}
