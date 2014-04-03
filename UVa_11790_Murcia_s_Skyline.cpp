#include <iostream>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 3010;
int N, nCase, cnt, increase[MAXN], decrease[MAXN], maxIncrease, maxDecrease;

struct Building {
    int height, width;
    Building(int h = 0, int w = 0) {
        height = h;  width = w;
    }
} building[MAXN];

void init() {
    cnt++;
    memset(increase, 0, sizeof(increase));
    memset(decrease, 0, sizeof(decrease));
    maxIncrease = maxDecrease = 0;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> building[i].height;
    }
    for (int i = 0; i < N; i++) {
        cin >> building[i].width;
    }
}

void work() {
    for (int i = 0; i < N; i++) {
        increase[i] = decrease[i] = building[i].width;
        for (int j = 0; j < i; j++) {
            if (building[i].height > building[j].height) {
                if (increase[j] + building[i].width > increase[i]) {
                    increase[i] = increase[j] + building[i].width;
                }
            }
            if (building[i].height < building[j].height) {
                if (decrease[j] + building[i].width > decrease[i]) {
                    decrease[i] = decrease[j] + building[i].width;
                }
            }
        }
        if (increase[i] > maxIncrease) {
            maxIncrease = increase[i];
        }
        if (decrease[i] > maxDecrease) {
            maxDecrease = decrease[i];
        }
    }
}

void output() {
    cout << "Case " << cnt << ". ";
    if (maxIncrease >= maxDecrease) {
        cout << "Increasing (" << maxIncrease << ").";
        cout << " ";
        cout << "Decreasing (" << maxDecrease << ").";
    } else {
        cout << "Decreasing (" << maxDecrease << ").";
        cout << " ";
        cout << "Increasing (" << maxIncrease << ").";
    }
    cout << endl;
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
