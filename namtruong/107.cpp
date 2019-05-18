#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E3;

vector < int > graph[MAX + 5];
vector < pair < int , int > > edge;
bool visit[MAX + 5];
int cnt = 0;

void dfs(int u) {
    cnt++;
    visit[u] = true;
    for (int i = 0 ; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visit[v]) {
            edge.push_back(make_pair(u, v));
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, s;
        cin >> n >> m >> s;
        for (int i = 1 ; i <= n; i++) graph[i].clear();
        memset(visit, false, sizeof visit);
        edge.clear();
        while (m--) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cnt = 0;
        dfs(s);
        if (cnt == n) {
            for (int i = 0 ; i < edge.size(); i++) {
                cout << edge[i].first << " " << edge[i].second << endl;
            }
        }
        else cout << -1 << endl;
    }
}