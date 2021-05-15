#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

queue < pair < int, pair < int, int > > > q;
int n;
int u, v, z, t;
char a[105][105];

void bfs(int i, int j) {
    q.push(make_pair(0, make_pair(i, j)));
    a[i][j] = 'X';
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.second.first;
        int y = cur.second.second;
        int cnt = cur.first;
        if (x == z && y == t) {
            cout << cnt;
            return;
        }
        for (int i = 1 ; i <= n - y; i++) {
            if (a[x][y + i] == 'X') break;
            if (a[x][y + i] == '.') {
                q.push(make_pair(cnt + 1, make_pair(x, y + i)));
                a[x][y + i] = 'X';
            }
        }
        for (int i = 1 ; i <= y - 1; i++) {
            if (a[x][y - i] == 'X') break;
            if (a[x][y - i] == '.') {
                q.push(make_pair(cnt + 1, make_pair(x, y - i)));
                a[x][y - i] = 'X';
            }
        }
        for (int i = 1 ; i <= n - x; i++) {
            if (a[x + i][y] == 'X') break;
            if (a[x + i][y] == '.') {
                q.push(make_pair(cnt + 1, make_pair(x + i, y)));
                a[x + i][y] = 'X';
            }
        }
        for (int i = 1 ; i <= x - 1; i++) {
            if (a[x - i][y] == 'X') break;
            if (a[x - i][y] == '.') {
                q.push(make_pair(cnt + 1, make_pair(x - i, y)));
                a[x - i][y] = 'X';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1 ; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cin >> u >> v >> z >> t;
    u++;
    v++;
    z++;
    t++;
    bfs(u, v);
}