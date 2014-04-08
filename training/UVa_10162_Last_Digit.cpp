#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int MAXN = 110;
long long pow[MAXN], sum[MAXN];
int n;
string line;

void init() {
    sum[0] = 0;
    for (int i = 1; i <= 100; i++) {
        pow[i] = 1;
        for (int j = 1; j <= i; j++) {
            pow[i] *= i;
            pow[i] %= 10;
        }
        sum[i] = sum[i-1] + pow[i];
        sum[i] %= 10;
    }
}

void output() {
    int index = line.length() < 2 ? 0 : line.length()-2;
    stringstream ss(line.substr(index));
    ss >> n;
    cout << sum[n] << endl;
}

int main() {
    init();
    while (getline(cin, line) && line != "0") {
        output();
    }
    return 0;
}
