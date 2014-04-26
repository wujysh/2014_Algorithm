#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector <int> unsortedStack, sortedStack;
vector <int>::iterator it;
string line;

void init() {
    unsortedStack.clear();
    sortedStack.clear();
}

void input() {
    stringstream ss(line);
    int x;
    while (ss >> x) {
        unsortedStack.push_back(x);
    }
}

void output() {
    for (int i = 0; i < unsortedStack.size(); i++) {
        if (i) cout << " ";
        cout << unsortedStack[i];
    }
    cout << endl;

    sortedStack = unsortedStack;
    sort(sortedStack.begin(), sortedStack.end());

    for (int i = unsortedStack.size() - 1; i >= 0; i--) {
        if (unsortedStack[i] != sortedStack[i]) {
            it = find(unsortedStack.begin(), unsortedStack.end(), sortedStack[i]);
            if (it == unsortedStack.begin()) {
                reverse(unsortedStack.begin(), unsortedStack.begin() + i + 1);
                cout << unsortedStack.size() - i << " ";
            } else {
                reverse(unsortedStack.begin(), it + 1);
                cout << unsortedStack.end() - it << " ";
                reverse(unsortedStack.begin(), unsortedStack.begin() + i + 1);
                cout << unsortedStack.size() - i << " ";
            }
        }
    }

    cout << 0 << endl;
}

int main() {
    ios::sync_with_stdio(false);
	while (getline(cin, line)) {
		init();
		input();
        output();
	}
	return 0;
}
