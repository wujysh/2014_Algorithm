#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2000;
int nCase, n, t, m, arriveTime[MAXN], arrived, times, trips;
bool first;

void init() {
    arrived = 0, times = 0, trips = 0;
}

void input() {
    cin >> n >> t >> m;
    for (int i = 0; i < m; i++) {
        cin >> arriveTime[i];
    }
}

void work() {
    sort(arriveTime, arriveTime + m);

    first = m % n;

    for (int i = 0; i < m; i++) {
        if (times < arriveTime[i]) {
            times = arriveTime[i];
        }
        arrived++;
        if (!first) {
            if (arrived == n) {
                trips++;
                times += 2 * t;
                arrived = 0;
            }
        } else if (arrived == m % n) {
            first = false;
            trips++;
            times += 2 * t;
            arrived = 0;
        }
    }
}

void output() {
    cout << times - t << " " << trips << endl;
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
