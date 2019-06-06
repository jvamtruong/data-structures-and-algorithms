#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < char > v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	cin.ignore();
	for (int i = 1 ; i <= t; i++) {
		string s;
		getline(cin, s);
		int ans = 0;
		v.clear();
		for (int j = 0 ; j < s.length(); j++) {
			if (s[j] == '[') {
				v.push_back(s[j]);
				ans = max(ans, (int) v.size());
			}
			else v.pop_back();
		}
		cout << i << " " << (1 << ans) << endl;
	}		
}