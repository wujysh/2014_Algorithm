#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

string strM, strN;
int m, n, cycle;
int lastDigit[10][4] = {0,0,0,0,
                        1,1,1,1,
                        6,2,4,8,
                        1,3,9,7,
                        6,4,6,4,
                        5,5,5,5,
                        6,6,6,6,
                        1,7,9,3,
                        6,8,4,2,
                        1,9,1,9};

void init() {
    cycle = 0;
    m = strM[strM.length()-1] - '0';
}

void output() {
    if (strN == "0") {
        cout << 1 << endl;
    } else {
        for (int i = 0; i < strN.length(); i++) {
            cycle = (cycle*10 + strN[i] - '0') % 4;
        }
        cout << lastDigit[m][cycle] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> strM >> strN && (strM != "0" || strN != "0")) {
        init();
        output();
    }
    return 0;
}
