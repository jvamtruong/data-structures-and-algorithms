#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E3;

int low[MAX + 5];
int number[MAX + 5];
int father[MAX + 5];
int order = 0;
int trace[MAX + 5][MAX + 5];
vector < int > graph[MAX + 5];
vector < int > bridge;

void dfs(int u) {
    number[u] = low[u] = ++order;
    for (int i = 0 ; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!number[v]) {
            father[v] = u;
            dfs(v);
            if (low[v] > number[u]) {
                if (trace[u][v]) bridge.push_back(trace[u][v]);
                else bridge.push_back(trace[v][u]);
            }
            low[u] = min(low[u], low[v]);
        }
        else if (v != father[u]) low[u] = min(low[u], number[v]);
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
        memset(number, 0, sizeof number);
        bridge.clear();
        for (int i = 1 ; i <= n; i++) graph[i].clear();
        for (int i = 1 ; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            trace[u][v] = i;
        }
        for (int i = 1 ; i <= n; i++) {
            if (!number[i]) {
                father[i] = -1;
                dfs(i);
            }
        }
        cout << bridge.size() << endl;
        for (int i = 0 ; i < bridge.size(); i++) {
            cout << bridge[i] << endl;
        }
    }       
}