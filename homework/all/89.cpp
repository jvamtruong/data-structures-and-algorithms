#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < int > graph[100];

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
        for (auto j : graph[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}