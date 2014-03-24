#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int m;
	cin >> m;
	cin.ignore();
	while (m--) {
		string line;
		int luggage[30], cnt = 1, sum = 0, dp[5000];

		getline(cin, line);
		stringstream ss(line);
		while (ss >> luggage[cnt]) {
			sum += luggage[cnt];
			cnt++;
		}
		if (sum % 2 != 0) {
			cout << "NO" << endl;
			continue;
		}

		memset(dp, 0, sizeof(dp));
		for (int i = 1; i < cnt - 1; i++) {
			for (int v = sum / 2; v >= luggage[i]; v--) {
				if (dp[v - luggage[i]] + luggage[i] > dp[v]) {
					dp[v] = dp[v - luggage[i]] + luggage[i];
				}
			}
		}

		if (dp[sum / 2] == sum / 2) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}
	return 0;
}
