#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 200;
int n, nCase = 0, height[MAXN];

struct Node {
	int a, b, s, h;
	friend bool operator<(const Node a, const Node b) {
		return a.s > b.s;
	}
	Node(int a1, int b1, int h1) {
		a = a1; b = b1; s = a1 * b1; h = h1;
	}
};
vector <Node> block, dp;

void init() {
    nCase++;
    block.clear();
    block.push_back(Node(INF, INF, 0));
    memset(height, 0, sizeof(height));
}

void input() {
    int x[35], y[35], z[35];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i];
        block.push_back(Node(x[i], y[i], z[i]));
        block.push_back(Node(x[i], z[i], y[i]));
        block.push_back(Node(y[i], z[i], x[i]));
        block.push_back(Node(y[i], x[i], z[i]));
        block.push_back(Node(z[i], x[i], y[i]));
        block.push_back(Node(z[i], y[i], x[i]));
    }
}

void work() {
    sort(block.begin() + 1, block.end());

    for (int i = 0; i < block.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (block[i].a < block[j].a && block[i].b < block[j].b) {
                if (height[j] + block[i].h > height[i]) {
                    height[i] = height[j] + block[i].h;
                }
            }
        }
    }
}

void output() {
    int ans = 0;
    for (int i = 1; i < block.size(); i++) {
        if (height[i] > ans)
            ans = height[i];
    }
    cout << "Case " << nCase << ": maximum height = " << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n && n) {
		init();
		input();
		work();
		output();
	}
	return 0;
}
