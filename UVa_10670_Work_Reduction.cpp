#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 110;
int nCase, cnt, N, M, L;

struct Agency {
    string name;
    int A, B;
    long long cost;
    friend bool operator<(Agency a, Agency b) {
        if (a.cost != b.cost) {
            return a.cost > b.cost;
        } else {
            return a.name > b.name;
        }
    }
};
vector <Agency> agency;
priority_queue <Agency> result;

void init() {
    cnt++;
    agency.clear();
    while (!result.empty()) result.pop();
}

void input() {
    cin >> N >> M >> L;
    cin.ignore();
    for (int i = 0; i < L; i++) {
        string line;
        char temp;
        Agency cur;
        getline(cin, line);
        int index = line.find(':');
        cur.name = line.substr(0, index);
        stringstream ss(line.substr(index+1));
        ss >> cur.A >> temp >> cur.B;
        cur.cost = 0;
        agency.push_back(cur);
    }
}

void work() {
    for (int i = 0; i < L; i++) {
        Agency cur = agency[i];
        long long cost = 0;
        int curUnits = N;

        while (curUnits / 2 >= M) {
            //cout << curUnits << " " << cost << endl;
            if (((curUnits+1) / 2) * cur.A > cur.B) {
                curUnits /= 2;
                cost += cur.B;
            } else {
                cost += ((curUnits+1) / 2) * cur.A;
                curUnits /= 2;
            }
        }
        cost += (curUnits-M) * cur.A;

        cur.cost = cost;
        result.push(cur);
    }
}

void output() {
    cout << "Case " << cnt << endl;
    while (!result.empty()) {
        Agency cur = result.top();
        result.pop();
        cout << cur.name << " " << cur.cost << endl;
    }
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
