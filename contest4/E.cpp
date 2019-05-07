#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < char > v;

//------------------------------------WA--------------------------------------//

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	int t;
	cin >> t;
	while (t--) {	
		string s;
		cin >> s;
		v.clear();
		int ans = 0;
		int cnt = 0;
		for (int i = 0 ; i < s.length(); i++) {
			if (s[i] == '(') v.push_back(s[i]);
			else {
				if (v.empty()) {
					cnt = 0;
				}
				else {
					if (v.back() == '(') {
						cnt += 2;
						v.pop_back();
					}
				}	
			}
			ans = max(ans, cnt);
		}
		cout << ans << endl;
	}
}