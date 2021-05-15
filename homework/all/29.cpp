#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < char > v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	string s;
	cin >> n >> k >> s;
	for (int i = 0 ; i < n; i++) {
		while (k > 0 && !v.empty() && v.back() < s[i]) {
			v.pop_back();
			k--;
		}
		v.push_back(s[i]);
	}
	for (int i = 0 ; i < v.size(); i++) {
		cout << v[i];
	}
}