#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int MAXN = 10000010;
bool visited[MAXN];
int STEP, MOD, ans;

void init() {
    memset(visited, false, sizeof(visited));
    ans = 0;
}

void work() {
    long long num = 0;
    while (true) {
        num = (num + STEP) % MOD;
        if (visited[num]) {
            break;
        } else {
            ans++;
            visited[num] = true;
        }
    }
}

void output() {
    cout << setw(10) << STEP << setw(10) << MOD << "    ";
    if (ans == MOD) {
        cout << "Good Choice" << endl;
    } else {
        cout << "Bad Choice" << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> STEP >> MOD) {
        init();
        work();
        output();
    }
    return 0;
}

/*
#include<iostream>
#include<cstdio>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    int s, m;
    while(cin >> s >> m) {
        if (gcd(s, m) == 1)
            printf("%10d%10d    Good Choice\n\n", s, m);
        else
            printf("%10d%10d    Bad Choice\n\n", s, m);
    }
    return 0;
}
*/
