#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1010;
int numerator, denominator, visited[MAXN], pos, cnt;
vector <int> ans;

void init() {
    memset(visited, 0, sizeof(visited));
    ans.clear();
    pos = 1;
    cnt = 1;
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
    cout << ".";

    int cycleStart = visited[numerator];
    for (int i = 1; i < cycleStart; i++) {
        if (cnt % 50 == 0) cout << endl;
        cout << ans[i];
        cnt++;
    }

    int len = pos - cycleStart;
    if (len == 1 && ans[cycleStart] == 0) {
        cout << endl;
        cout << "This expansion terminates." << endl;
    } else {
        for (int i = 0; i < len; i++) {
            if (cnt % 50 == 0) cout << endl;
            cout << ans[cycleStart+i];
            cnt++;
        }
        cout << endl;
        cout << "The last " << len << " digits repeat forever." << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> numerator >> denominator && (numerator || denominator)) {
        init();
        findCycle();
        output();
    }
    return 0;
}
