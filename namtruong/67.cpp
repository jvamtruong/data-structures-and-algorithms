#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < int > v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while (cin >> s) {
		v.clear();
		int cnt = 0;
		for (int i = 0 ; i < s.length(); i++) {
			if (s[i] == '(') {
				cnt++;
				cout << cnt << " ";
				v.push_back(cnt);
			}	
			if (s[i] == ')') {
				cout << v.back() << " ";
				v.pop_back();
			}
		}
		cout << endl;
	}
}