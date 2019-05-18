#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

//---https://vn.spoj.com/problems/GRAPH_/

const int MAX = 1E4;

int low[MAX + 5];
int number[MAX + 5];
int father[MAX + 5];
int order = 0;
int child = 0;
int cut_vertice = 0;
int bridge = 0;
bool articulation[MAX + 5];
vector < int > graph[MAX + 5];

void dfs(int u) {
    number[u] = low[u] = ++order;
    for (int i = 0 ; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!number[v]) {
            father[v] = u;
            if (father[u] == -1) child++;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= number[u]) articulation[u] = true;
            if (low[v] > number[u]) bridge++;
        }
        else if (v != father[u]) low[u] = min(low[u], number[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }           
    for (int i = 1 ; i <= n; i++) {
        if (!number[i]) {
            child = 0;
            father[i] = -1;
            dfs(i);
            articulation[i] = (child > 1);
        }
    }
    for (int i = 1 ; i <= n; i++) cut_vertice += articulation[i];
    cout << cut_vertice << " " << bridge;
}   
