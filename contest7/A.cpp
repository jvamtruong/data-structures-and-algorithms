#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct data {
	string father;
	string son;
	int age;
};

data a[105];
vector < pair < string, int > > v;
int n;

bool cmp(pair < string, int > u, pair < string, int > v) {
	if (u.second > v.second) return 1;
	if (u.second == v.second) {
		if (u.first < v.first) return 1;
	}
	return 0;
}

void dfs(string father, int age) {
	for (int i = 0 ; i < n; i++) {
		if (a[i].father == father) {
			v.push_back(make_pair(a[i].son, age - a[i].age));
			dfs(a[i].son, age - a[i].age);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int j = 1 ; j <= t; j++) {
		cin >> n;
		for (int i = 0 ; i < n; i++) {
			cin >> a[i].father >> a[i].son >> a[i].age;
		}
		v.clear();
		dfs("Ted", 100);
		sort(v.begin(), v.end(), cmp);
		cout << "DATASET" << " " << j << endl;
		for (int i = 0 ; i < v.size(); i++) {
			cout << v[i].first << " " << v[i].second << endl;
		}
	}
}