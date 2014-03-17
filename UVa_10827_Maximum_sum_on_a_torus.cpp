#include <iostream>
using namespace std;

const int MAXN = 260;
int nCase, N, a[MAXN][MAXN], b[MAXN], result;

int MaxSum(int n) {
	int res = 0;
	for (int i = 1; i <= N+1; i++) {
        int sum = 0;
        for (int j = i; j < i+N; j++) {
            if (sum > 0) {
                sum += b[j];
            } else {
                sum = b[j];
            }
            if (sum > res) {
                res = sum;
            }
        }
	}
	return res;
}

int MaxSum2(int m, int n) {
	int res = 0;
	for (int i = 1; i <= m; i++) {
		for (int k = 1; k <= n; k++) {
			b[k] = 0;
		}
		for (int j = i; j < i+N; j++) {
			for (int k = 1; k <= n; k++) {
				b[k] += a[j][k];
			}
			int sum = MaxSum(n);
			if (sum > res) {
                res = sum;
			}
		}
	}
	return res;
}

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
            a[i + N][j] = a[i][j + N] = a[i + N][j + N] = a[i][j];
        }
    }
}

void work() {
    result = MaxSum2(2*N, 2*N);
}

void output() {
    cout << result << endl;
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
