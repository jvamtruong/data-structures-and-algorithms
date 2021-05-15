#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < int > graph[1005];
queue < int > q;
bool visit[1005];

void bfs(int u) {
    q.push(u);
    visit[u] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0 ; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!visit[v]) {
                q.push(v);
                visit[v] = true;
            }
        }
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
        memset(visit, false, sizeof visit);
        for (int i = 1 ; i <= n; i++) graph[i].clear();
        while (m--) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bfs(u);
        cout << endl;
    }  
}