#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

//-------------------???-------------------------//

map < string, int> Map;
set < string > s;
set < string > :: iterator it;
bool visit[100][100];
vector < pair < char, int > > v;
string temp = "";
char a[100][100];
int n;
int dx[10] = {0, 0, -1, -1, -1, 1, 1, 1};
int dy[10] = {1, -1, 1, 0, -1, 1, 0, -1};

void dfs(int x, int y, int len) {
	visit[x][y] = true;
	temp.push_back(a[x][y]);
	if (a[x][y] == 'q') temp.push_back('u');
	cout << temp << endl;
	for (int i = 0 ; i < 8; i++) {
		int u = x + dx[i];
		int v = y + dy[i];
		if (0 < u && u < n && 0 < v && v < n && !visit[u][v]) {
			if (temp.length() == len) {
				if (Map[temp]) {
					if (!s.count(temp)) s.insert(temp);
				}
			}
			else {
				visit[u][v] = true;
				dfs(u, v, len);
			}
			temp.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int m;
	cin >> m;
	for (int i = 0 ; i < m; i++) {
		string str;
		cin >> str;
		Map[str]++;
		v.push_back(make_pair(str[0], str.length()));
	}		
	while (true) {
		cin >> n;
		if (n == 0) return 0;
		s.clear();
		temp.clear();
		memset(visit, false, sizeof visit);
		for (int i = 0 ; i < n; i++) {
			for (int j = 0 ; j < n; j++) {
				cin >> a[i][j];
			}
		}
		for (int k = 0 ; k < m; k++) {
			for (int i = 0 ; i < n; i++) {
				for (int j = 0 ; j < n; j++) {
					if (a[i][j] == v[k].first) {
						cout << a[i][j] << " " << i << " " << j << endl;
						memset(visit, false, sizeof visit);
						temp.clear();
						dfs(i, j, v[k].second);
					}
				}
			}
		}
		for (it = s.begin() ; it != s.end(); it++) {
			cout << *it << endl;
		}
		cout << '-' << endl;
	}
}