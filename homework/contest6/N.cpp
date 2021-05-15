#include<bits/stdc++.h>
#define endl '\n'
using namespace std;




int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cin.ignore();
	for (int j = 1 ; j <= n; j++) {
		string s;
		getline(cin, s);
		s += ' ';
		int val = 0;
		for (int i = 0 ; i < s.length(); i++) {
			if (s[i] == ' ') {
				if (val > j) {
					cout << j << " " << val << endl;
				}
				val = 0;
			}
			else val = val * 10 + (s[i] - '0');
		}
	}	
}