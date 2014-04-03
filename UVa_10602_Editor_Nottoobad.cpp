#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 110;
int nCase, n, ans;
string word[MAXN];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word[i];
    }
}

void work() {
    sort(word, word + n);

    ans = word[0].length();

    for (int i = 1; i < n; i++) {
        int index = word[i - 1].length();
        for (int j = 0; j < word[i - 1].length(); j++) {
            if (word[i - 1][j] != word[i][j]) {
                index = j;
                break;
            }
        }
        ans += word[i].length() - index;
    }
}

void output() {
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << word[i] << endl;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin >> nCase;
	while (nCase--) {
		input();
		work();
		output();
	}
	return 0;
}
