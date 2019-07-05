// http://vnoi.info/wiki/translate/topcoder/Range-Minimum-Query-and-Lowest-Common-Ancestor#b%C3%A0i-to%C3%A1n-lca_thu%E1%BA%ADt-to%C3%A1n-o-nlogn-o-logn
// < O(NlogN), O(logN) > 
vector < int > graph[MAX + 5];

int par[MAX + 5];
int p[MAX + 5][30];
int h[MAX + 5];
bool visit[MAX + 5];

void dfs(int u) {
    visit[u] = true;
    for (int v : graph[u]) {
        if (!visit[v]) {
            par[v] = u;
            h[v] = h[u] + 1;
            dfs(v);
        }
    }
}

void preCompute() {
    for (int i = 1 ; i <= n; i++) {
        for (int j = 0 ; (1 << j) < n; j++) {
            p[i][j] = -1;
        }
    }
    for (int i = 1 ; i <= n; i++) {
        p[i][0] = par[i];
    }
    for (int j = 1 ; (1 << j) < n; j++) {
        for (int i = 1 ; i <= n; i++) {
            if (p[i][j - 1] != -1) {
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
    }
}

int LCA(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int k = log(u) / log(2);
    for (int i = k ; i >= 0; i--) {
        if (h[u] - (1 << i) >= h[v]) {
            u = p[u][i];
        }
    }
    if (u == v) return u;
    for (int i = k ; i >= 0; i--) {
        if (p[u][i] != -1 && p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return par[u];
}
