#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 25;
const long long INF = -2147483648LL;
int nCase, A, B, C;
long long a[MAXN][MAXN][MAXN], b[MAXN][MAXN], c[MAXN], result;

long long MaxSum(int n) {
	long long res = INF, sum = 0;
    for (int i = 1; i <= n; i++) {
        if (sum > 0) {
            sum += c[i];
        } else {
            sum = c[i];
        }
        if (sum > res) {
            res = sum;
        }
    }
	return res;
}

long long MaxSum2(int m, int n) {
	long long res = INF, sum = 0;
	for (int i = 1; i <= m; i++) {
		memset(c, 0, sizeof(c));
		for (int j = i; j <= m; j++) {
			for (int k = 1; k <= n; k++) {
				c[k] += b[j][k];
			}
			sum = MaxSum(n);
			if (sum > res) {
                res = sum;
			}
		}
	}
	return res;
}

long long MaxSum3(int l, int m, int n) {
	long long res = INF, sum = 0;
	for (int i = 1; i <= l; i++) {
        memset(b, 0, sizeof(b));
		for (int v = i; v <= l; v++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k <= n; k++) {
                    b[j][k] += a[v][j][k];
                }
            }
			sum = MaxSum2(m, n);
			if (sum > res) {
                res = sum;
			}
		}
	}
	return res;
}

void input() {
    cin >> A >> B >> C;
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            for (int k = 1; k <= C; k++) {
                cin >> a[i][j][k];
            }
        }
    }
}

void work() {
    result = MaxSum3(A, B, C);
}

void output() {
    cout << result << endl;
    if (nCase) cout << endl;
}

int main() {
    cin >> nCase;
    while (nCase--) {
		input();
		work();
		output();
	}
	return 0;
}
