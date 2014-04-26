#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int nCase, cnt, n, d, ans;
vector <int> stone;

void init() {
    cnt++;
    ans = 0;
    stone.clear();
}

void input() {
    cin >> n >> d;
    stone.push_back(0);
    for (int i = 0; i < n; i++) {
        char a;
        int b;
        cin >> a;
        cin.ignore();
        cin >> b;
        stone.push_back(b);
        if (a == 'B') stone.push_back(b);
    }
    stone.push_back(d);
}

void work() {
    //sort(stone.begin(), stone.end()); // already sorted
    for (int i = 3; i < stone.size(); i += 2) {
        if (stone[i] - stone[i - 2] > ans)
            ans = stone[i] - stone[i - 2];
    }
    for (int i = 2; i < stone.size(); i += 2) {
        if (stone[i] - stone[i - 2] > ans)
            ans = stone[i] - stone[i - 2];
    }
}

void output() {
    cout << "Case " << cnt << ": " << ans << endl;
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
