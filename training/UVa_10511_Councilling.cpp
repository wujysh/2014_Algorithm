#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int MAXN = 5000;
const int INF = 0x3f3f3f3f;

struct Edge {
	int u, v, c, next;
	Edge(int u0 = 0, int v0 = 0, int c0 = 0, int next0 = 0) {
		u = u0; v = v0; c = c0; next = next0;
	}
} edge[MAXN * 10];
int head[MAXN * 2], cnt;
bool visited[MAXN * 2];
int path[MAXN * 2], from, to, maxflow, offflow, nCase;
map <string, int> resident, party, club;
vector <string> idToString;
string line;

void init() {
	memset(head, -1, sizeof(head));
	cnt = 0;
	maxflow = 0;
	idToString.clear();
	club.clear();
	resident.clear();
	party.clear();
}

void addEdge(int u, int v, int c) {
	edge[cnt] = Edge(u, v, c, head[u]);
	head[u] = cnt++;
	edge[cnt] = Edge(v, u, 0, head[v]);
	head[v] = cnt++;
}

void input() {
    vector <string> inputData;

    while (getline(cin, line) && line != "") {
        inputData.push_back(line);
        stringstream ss(line);
        string residentName, partyName, clubName;
        ss >> residentName >> partyName;
        if (resident.find(residentName) == resident.end()) {
            resident[residentName] = resident.size();
        }
        if (party.find(partyName) == party.end()) {
            party[partyName] = party.size();
        }
        while (ss >> clubName) {
            if (club.find(clubName) == club.end()) {
                club[clubName] = club.size();
            }
        }
    }

//    map <string, int>::iterator it;
//    cout << "===========CLUB===========" << endl;
//    for (it = club.begin(); it != club.end(); it++) {
//        cout << it->second << " " << it->first << endl;
//    }
//    cout << "=========RESIDENT=========" << endl;
//    for (it = resident.begin(); it != resident.end(); it++) {
//        cout << it->second << " " << it->first << endl;
//    }
//    cout << "===========PARTY==========" << endl;
//    for (it = party.begin(); it != party.end(); it++) {
//        cout << it->second << " " << it->first << endl;
//    }

    int clubIdBase = 0, residentIdBase = club.size(), partyIdBase = club.size() + resident.size();
    from = 0;  to = partyIdBase + party.size() + 1;

    for (int i = 1; i <= club.size(); i++) {
        addEdge(from, i, 1);
    }
    for (int i = 1; i <= party.size(); i++) {
        addEdge(partyIdBase+i, to, (club.size()-1)/2);
    }
    idToString.resize(partyIdBase+1);
    for (int i = 0; i < inputData.size(); i++) {
        stringstream ss(inputData[i]);
        string residentName, partyName, clubName;
        ss >> residentName >> partyName;
        int residentId = residentIdBase + resident[residentName];
        idToString[residentId] = residentName;
        int partyId = partyIdBase + party[partyName];
        addEdge(residentId, partyId, 1);
        while (ss >> clubName) {
            int clubId = clubIdBase + club[clubName];
            idToString[clubId] = clubName;
            addEdge(clubId, residentId, 1);
        }
    }

//    cout << "============ID============" << endl;
//    for (int i = 0; i < idToString.size(); i++) {
//        cout << i << " " << idToString[i] << endl;
//    }
//    cout << "===========EDGE===========" << endl;
//    for (int i = 0; i < cnt; i++) {
//        cout << edge[i].u << " " << edge[i].v << " " << edge[i].c << endl;
//    }
}

bool bfs() {
	int s = from, d;
	queue <int> q;
	q.push(s);
	memset(visited, false, sizeof(visited));
	while (!q.empty()) {
		s = q.front();
		q.pop();
		visited[s] = true;
		for (int i = head[s]; i != -1; i = edge[i].next) {
			d = edge[i].v;
			if (!visited[d] && edge[i].c > 0) {
				path[d] = i;
				q.push(d);
				if (d == to) return true;
			}
		}
	}
	return false;
}

void work() {
	while (bfs()) {
		offflow = MAXN;
		for (int i = to; i != from; i = edge[path[i]].u) {
			if (edge[path[i]].c < offflow)
				offflow = edge[path[i]].c;
		}
		for (int i = to; i != from; i = edge[path[i]].u) {
			edge[path[i]].c -= offflow;
			edge[path[i] ^ 1].c += offflow;
		}
		maxflow += offflow;
	}
}

void output() {
    if (maxflow == club.size()) {
        for (int i = 0; i < cnt; i++) {
            if (edge[i].c == 0 && edge[i].u >= 1 && edge[i].u <= club.size() && edge[i].v >= club.size()+1 && edge[i].v <= club.size()+resident.size()) {
                cout << idToString[edge[i].v] << " " << idToString[edge[i].u] << endl;
            }
        }
    } else {
        cout << "Impossible." << endl;
    }
    if (nCase) cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
	cin >> nCase;
	cin.ignore();
	getline(cin, line);
	while (nCase--) {
		init();
		input();
		work();
		output();
	}
	return 0;
}
