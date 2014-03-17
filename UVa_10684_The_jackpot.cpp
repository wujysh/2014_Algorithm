#include <iostream>
#include <cstring>
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;

const int MAXN = 100010;
int a[MAXN], n;
long long dp[MAXN], ans;

void input() {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void work() {
    ans = dp[0] = a[0];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < n; i++) {
        dp[i] = max(0, dp[i - 1] + a[i]);
        if (dp[i] > ans) ans = dp[i];
    }
}

void output() {
    if (ans > 0) {
        cout << "The maximum winning streak is " << ans << "." << endl;
    } else {
        cout << "Losing streak." << endl;
    }
}

int main() {
	while (cin >> n && n) {
		input();
		work();
		output();
	}
	return 0;
}
