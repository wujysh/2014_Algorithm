#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map <int, int> dimenCount;
vector <int> bag;
vector <vector <int> > piece;
int maxDimenCount, n;

void init() {
    dimenCount.clear();
    bag.clear();
    piece.clear();
    maxDimenCount = 1;
}

void input() {
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bag.push_back(x);
        if (dimenCount.find(x) != dimenCount.end()) {
            dimenCount[x]++;
            if (dimenCount[x] > maxDimenCount) maxDimenCount = dimenCount[x];
        } else {
            dimenCount[x] = 1;
        }
    }
}

void work() {
    sort(bag.begin(), bag.end());

    piece.resize(maxDimenCount);
    int j = 0;
    for (int i = 0; i < bag.size(); i++) {
        piece[j].push_back(bag[i]);
        j = (j + 1) % maxDimenCount;
    }
}

void output() {
    cout << maxDimenCount << endl;
    for (int i = 0; i < piece.size(); i++) {
        for (int j = 0; j < piece[i].size(); j++) {
            if (j) cout << " ";
            cout << piece[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
	while (cin >> n && n) {
        init();
        input();
        work();
        output();
	}
	return 0;
}
