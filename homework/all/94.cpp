#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E3;

vector < int > graph[MAX + 5];
bool visit[MAX + 5];

void dfs(int u) {
    visit[u] = true;
    for (int i = 0 ; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visit[v]) dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1 ; i <= n; i++) graph[i].clear();
        while (m--) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int q;
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            memset(visit, false, sizeof visit);
            dfs(u);
            if (visit[v]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}