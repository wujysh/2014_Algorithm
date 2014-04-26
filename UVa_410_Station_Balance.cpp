#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

int c, s, nCase, sum;
double ave, imbalance;
vector <int> specimen, chamber[6];

void init() {
    nCase++;
    sum = 0;
    imbalance = 0.0;
    specimen.clear();
    for (int i = 0; i < 6; i++) {
        chamber[i].clear();
    }
}

void input() {
    for (int i = 0; i < s; i++) {
        int x;
        cin >> x;
        sum += x;
        specimen.push_back(x);
    }
    ave = (double)sum / c;

    for (int i = 0; i < 2 * c - s; i++) {
        specimen.push_back(0);
    }
}

void work() {
    sort(specimen.begin(), specimen.end());

    for (int i = 0; i < specimen.size() / 2; i++) {
        if (specimen[i])
            chamber[i].push_back(specimen[i]);
        if (specimen[specimen.size() - i - 1])
            chamber[i].push_back(specimen[specimen.size() - i - 1]);
    }
}

void output() {
    cout << "Set #" << nCase << endl;
    for (int i = 0; i < c; i++) {
        cout << setw(2) << i << ":";
        int sum = 0;
        for (int j = 0; j < chamber[i].size(); j++) {
            cout << " " << chamber[i][j];
            sum += chamber[i][j];
        }
        imbalance += fabs(double(sum) - ave);
        cout << endl;
    }
    cout << "IMBALANCE = " << setprecision(5) << fixed << imbalance << endl;
    cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> c >> s) {
        init();
        input();
        work();
        output();
	}
	return 0;
}
