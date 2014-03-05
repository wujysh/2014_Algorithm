#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 310;
char line[255];
int s, l1, l2, cnt;
long long sum, dp[MAXN][MAXN];

void init() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= 300; i++) {  // 当前放的币值
        for (int v = i; v <= 300; v++) {  // 要凑的总和
            for (int k = 1; k <= 300; k++) {  // 组成总和所用的钱币数量
                dp[v][k] += dp[v-i][k-1];
            }
        }
    }
}

void work() {
    if (l1 > 300) l1 = 300;
    if (l2 > 300) l2 = 300;
    if (cnt == 1) {
        l2 = 300;  l1 = 0;
    }
    if (cnt == 2) {
        l2 = l1;  l1 = 0;
    }
    if (l1 < 0) l1 = 0;
    if (l2 < 0) l2 = 0;

    sum = 0;
    for (int i = l1; i <= l2; i++) {
        sum += dp[s][i];
    }
}

void output() {
    printf("%lld\n", sum);
}

int main() {
    init();
    while (gets(line) != NULL) {
        cnt = sscanf(line, "%d%d%d", &s, &l1, &l2);
        work();
        output();
    }
    return 0;
}


/**
* 以下算法用到了Ferrers图性质
*（整数n拆分成k个数之和的种数，与数n拆分成最大为k的数之和的种数相等。）
*/
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 310;
long long dp[MAXN][MAXN];

int main() {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i <= 300; i++) dp[0][i] = 1;
	for (int i = 1; i <= 300; i++) {
		for (int v = 1; v <= 300; v++) {
			if (v >= i) dp[v][i] = dp[v][i - 1] + dp[v - i][i];
			else dp[v][i] = dp[v][i - 1];
		}
	}

	char line[255];
	while (gets(line) != NULL) {
		int s, l1, l2;
		int cnt = sscanf(line, "%d%d%d", &s, &l1, &l2);

		if (l1 > 300) l1 = 300;
		if (l2 > 300) l2 = 300;
		if (cnt == 1) {
			l2 = 300;
			l1 = 0;
		}
		if (cnt == 2) {
			l2 = l1;
			l1 = 0;
		}
		if (l1 < 0) l1 = 0;
		if (l2 < 0) l2 = 0;

        if (s == 0 && l1 == 0) printf("1\n");
        else printf("%lld\n", dp[s][l2] - dp[s][l1-1]);
	}
	return 0;
}
*/
