#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < int > g[100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}		
	for (int i = 1 ; i <= n; i++) {
		for (int j = 0 ; j < g[i].size(); j++) {
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}