#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < int > graph[1005];
bool visit[1005];

void dfs(int u) {
    cout << u << " ";
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
        int n, m, u;
        cin >> n >> m >> u;
        for (int i = 1 ; i <= n; i++) graph[i].clear();
        memset(visit, false, sizeof visit);
        while (m--) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(u);
        cout << endl;
    }       
}