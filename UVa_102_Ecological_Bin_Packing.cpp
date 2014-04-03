#include <iostream>
#include <string>
using namespace std;

// num[bin No.][bottle color] = number of this kind of bottles
// color: 0-B, 1-G, 2-C
int num[3][3], cnt[6], mini;
string outputString[6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

void init() {
    mini = 0;
}

void work() {
    // case 0 BCG: move blue bottles in bin #1 and # 2 to bin #0. and so on
    cnt[0] = num[1][0] + num[2][0] + num[0][2] + num[2][2] + num[0][1] + num[1][1];
    // case 1 BGC
    cnt[1] = num[1][0] + num[2][0] + num[0][1] + num[2][1] + num[0][2] + num[1][2];
    // case 2 CBG
    cnt[2] = num[1][2] + num[2][2] + num[0][0] + num[2][0] + num[0][1] + num[1][1];
    // case 3 CGB
    cnt[3] = num[1][2] + num[2][2] + num[0][1] + num[2][1] + num[0][0] + num[1][0];
    // case 4 GBC
    cnt[4] = num[1][1] + num[2][1] + num[0][0] + num[2][0] + num[0][2] + num[1][2];
    // case 5 GCB
    cnt[5] = num[1][1] + num[2][1] + num[0][2] + num[2][2] + num[0][0] + num[1][0];

    for (int i = 0; i < 6; i++) {
        if (cnt[i] < cnt[mini]) {
            mini = i;
        }
    }
}

void output() {
    cout << outputString[mini] << " " << cnt[mini] << endl;
}

int main() {
    ios::sync_with_stdio(false);
	while (cin >>
		num[0][0] >> num[0][1] >> num[0][2] >>
		num[1][0] >> num[1][1] >> num[1][2] >>
		num[2][0] >> num[2][1] >> num[2][2]) {

        init();
        work();
        output();
	}
	return 0;
}
