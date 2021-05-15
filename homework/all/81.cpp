#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 500;

int a[MAX + 5][MAX + 5];
int n, m;
int ans = 0;
int dx[10] = {0, 0, 1, -1};
int dy[10] = {1, -1, 0, 0};
queue < pair < int, int > > q, temp;

void bfs() {
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1 ; j <= m; j++) {
            if (a[i][j] == 2) q.push(make_pair(i, j));
        }
    }
    while (!q.empty()) {
        while (!q.empty()) {
            pair < int, int > cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            for (int i = 0 ; i < 4; i++) {
                int u = x + dx[i];
                int v = y + dy[i];
                if (1 <= u && u <= n && 1 <= v && v <= m && a[u][v] == 1) {
                    temp.push(make_pair(u, v));
                    a[u][v] = 2;
                }
            }
        }
        if (!temp.empty()) ans++;
        while (!temp.empty()) {
            q.push(temp.front());
            temp.pop();
        }
    }
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1 ; j <= m; j++) {
            if (a[i][j] == 1) {
                cout << -1;
                return;
            }
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1 ; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    bfs();
}