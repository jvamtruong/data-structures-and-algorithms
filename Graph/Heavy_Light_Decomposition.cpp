// http://vnoi.info/wiki/algo/data-structures/heavy-light-decomposition

vector < int > graph[MAX + 5];
bool visit[MAX + 5];
int par[MAX + 5];
int chainIndex[MAX + 5];
int chainHead[MAX + 5];
int pos[MAX + 5];
int vertex[MAX + 5];
int treeSize[MAX + 5];
int base = 0;
int sz = 1;

void dfs(int u) {
	visit[u] = true;
	treeSize[u] = 1;
	for (int v : graph[u]) {
		if (!visit[v]) {
			par[v] = u;
			dfs(v);
			treeSize[u] += treeSize[v];
		}
	}
}

void hld(int u) {
	if (chainHead[sz] == 0) chainHead[sz] = u;
	chainIndex[u] = sz;
	pos[u] = ++base;
	vertex[base] = u;
	int hVertex = -1;
	for (int v : graph[u]) {
		if (v != par[u]) {
			if (hVertex == -1 || treeSize[v] > treeSize[hVertex]) {
				hVertex = v;
			}
		}
	}
	if (hVertex > -1) hld(hVertex);
	for (int v : graph[u]) {
		if (v != par[u] && v != hVertex) {
			sz++;
			hld(v);
		}
	}
}