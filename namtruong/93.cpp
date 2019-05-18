#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 100;

char a[MAX + 5][MAX + 5];
int dx[10] = {0, 0, -1, -1, -1, 1, 1, 1};
int dy[10] = {1, -1, 0, 1, -1, 0, 1, -1};
int n, m;

void dfs(int x, int y) {
    a[x][y] = '.';
    for (int i = 0 ; i < 8; i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        if (1 <= u && u <= n && 1 <= v && v <= m && a[u][v] == 'W') dfs(u, v);
    }
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
    int ans = 0;
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1 ; j <= m; j++) {
            if (a[i][j] == 'W') {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
}