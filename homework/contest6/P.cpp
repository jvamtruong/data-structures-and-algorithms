#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
 
int a[1005][1005];
 
int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 1 ; i <= n; i++) {
		string s;
		getline(cin, s);
		s += ' ';
		int val = 0;
		for (int j = 0 ; j < s.length(); j++) {
			if (s[j] == ' ') {
				a[i][val] = 1;
				val = 0;
			}
			else val = val * 10 + (s[j] - '0');
		}
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}