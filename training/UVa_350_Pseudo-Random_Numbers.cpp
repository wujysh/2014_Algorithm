#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 10010;
bool visited[MAXN];
int Z, I, M, L, ans, cnt;

void init() {
    cnt++;
    memset(visited, false, sizeof(visited));
    ans = 0;
}

void work() {
    long long num = L;
    while (true) {
        num = (Z * num + I) % M;
        if (visited[num]) {
            break;
        } else {
            ans++;
            visited[num] = true;
        }
    }
}

void output() {
    cout << "Case " << cnt << ": " << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> Z >> I >> M >> L && (Z || I || M || L)) {
        init();
        work();
        output();
    }
    return 0;
}
