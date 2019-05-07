#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

long long a[100000];

//-----------------------------RTE--------------------------------------------//

int main() {
	//ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		fflush(stdin);
		string s, p;
		getline(cin, s);
		fflush(stdin);
		getline(cin, p);
		fflush(stdin);
		s.insert(0, " ");
		s.push_back(' ');
		p.insert(0, " ");
		p.push_back(' ');
		memset(a, 0, sizeof a);
		//cout << s << endl << p;
		long long val = 0;
		long long deg = 0;
		bool bl1 = false;
		bool bl2 = false;
		for (int i = 0 ; i < s.length(); i++) {
			if (s[i] == ' ') {
				a[deg] += val;
				val = 0;
				deg = 0;
				bl1 = false;
				bl2 = false;
				continue;
			}
			if (s[i] >= '0' && s[i] <= '9' && !bl1) val = val * 10 + (s[i] - '0');
			if (s[i] == '*') bl1 = true;
			if (s[i] == '^') bl2 = true;
			if (s[i] >= '0' && s[i] <= '9' && bl2) deg = deg * 10 + (s[i] - '0');
		}
		for (int i = 0 ; i < p.length(); i++) {
			if (p[i] == ' ') {
				a[deg] += val;
				val = 0;
				deg = 0;
				bl1 = false;
				bl2 = false;
				continue;
			}
			if (p[i] >= '0' && p[i] <= '9' && !bl1) val = val * 10 + (p[i] - '0');
			if (p[i] == '*') bl1 = true;
			if (p[i] == '^') bl2 = true;
			if (p[i] >= '0' && p[i] <= '9' && bl2) deg = deg * 10 + (p[i] - '0');
		}
		int idx;
		for (int i = 0 ; i <= 10000; i++) {
			if (a[i]) {
				idx = i;
				break;
			}
		}
		for (int i = 10000 ; i > idx; i--) {
			if (a[i]) {
				cout << a[i] << "*x^" << i <<  " " << "+" << " ";
			}
		}
		cout << a[idx] << "*x^" << idx << endl;
	}	
}