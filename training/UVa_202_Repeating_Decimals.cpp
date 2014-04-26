#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 3010;
int numerator, numerator0, denominator, visited[MAXN], pos;
vector <int> ans;

void init() {
    memset(visited, 0, sizeof(visited));
    numerator0 = numerator;
    ans.clear();
    pos = 1;
}

void findCycle() {
    while (true) {
        ans.push_back(numerator / denominator);
        numerator %= denominator;
        if (visited[numerator]) {
            return;
        } else {
            visited[numerator] = pos;
            numerator *= 10;
            pos++;
        }
    }
}

void output() {
    cout << numerator0 << "/" << denominator << " = " << numerator0/denominator << ".";

    int cycleStart = visited[numerator];
    for (int i = 1; i < cycleStart; i++) {
        cout << ans[i];
    }
    cout << "(";
    int len = pos - cycleStart;
    for (int i = 0; i < (len <= 50 ? len : 50); i++) {
        cout << ans[cycleStart+i];
    }
    if (len > 50) cout << "...";
    cout << ")" << endl;
    cout << "   " << len << " = number of digits in repeating cycle" << endl;
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> numerator >> denominator) {
        init();
        findCycle();
        output();
    }
    return 0;
}
