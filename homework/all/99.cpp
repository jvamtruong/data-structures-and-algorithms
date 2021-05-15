#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int x, y, z, t;
bool visit[100][100];
int dx[10] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[10] = {2, -2, 1, -1, 2, -2, 1, -1};
queue < pair < int, pair < int, int > > > q;

void bfs(int x, int y) {
    q.push(make_pair(0, make_pair(x, y)));
    visit[x][y] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.second.first == z && cur.second.second == t) {
            cout << cur.first << endl;
            return;
        }
        for (int i = 0 ; i < 8; i++) {
            int u = cur.second.first + dx[i];
            int v = cur.second.second + dy[i];
            if (1 <= u && u <= 8 && 1 <= v && v <= 8 && !visit[u][v]) {
                q.push(make_pair(cur.first + 1, make_pair(u, v)));
                visit[u][v] = true;
            }
        }
    }
}

int val(char ch) {
    if (ch == 'a') return 1;
    return val(ch - 1) + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
        string a, b;
        cin >> a >> b;
        x = val(a[0]);
        y = a[1] - '0';
        z = val(b[0]);
        t = b[1] - '0';
        while (!q.empty()) q.pop();
        memset(visit, false, sizeof visit);
        bfs(x, y);
    }
}