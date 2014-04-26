#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1000;
bool visited[MAXN];
int square[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
int sum, cnt, num, N, nCase;

void init() {
    cnt++;
    memset(visited, false, sizeof(visited));
}

void input() {
    cin >> N;
    sum = N;
}

void findCycle() {
    while (true) {
        num = sum;
        sum = 0;
        while (num) {
            sum += square[num % 10];
            num /= 10;
        }
        if (visited[sum]) {
            return;
        } else {
            visited[sum] = true;
        }
    }
}

void output() {
    cout << "Case #" << cnt << ": " << N;
    if (sum == 1) {
        cout << " is a Happy number." << endl;
    } else {
        cout << " is an Unhappy number." << endl;
    }
}

int main() {
    cin >> nCase;
    while (nCase--) {
        init();
        input();
        findCycle();
        output();
    }
    return 0;
}
