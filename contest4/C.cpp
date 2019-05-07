#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int prior(char ch) {
	if (ch == '*' || ch == '/') return 2;
	if (ch == '+' || ch == '-') return 1;
	if (ch == '(') return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string st = "";
		string v = ""; 
		for (int i = 0 ; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
				st += ' ';
				st += s[i];
				st += ' ';
				continue;
			}
			st += s[i];
		}
		for (int i = 0 ; i < st.length(); i++) {
			if (st[i] == ' ') continue;
			else {
				if (st[i] >= 'a' && st[i] <= 'z') cout << st[i];
				else {
					if (st[i] == '(') v.push_back(st[i]);
					if (st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/') {
						while (!v.empty() && prior(v.back()) >= prior(st[i])) {
							if (v.back() != '(') cout << v.back();
							v.pop_back();
						}
						v.push_back(st[i]);
					}
					if (st[i] == ')') {
						while (!v.empty() && v.back() != '(') {
							cout << v.back();
							v.pop_back();
						}
						if (!v.empty()) v.pop_back();
					}
				}
			}
		}
		while (!v.empty()) {
			cout << v.back();
			v.pop_back();
		}
		cout << endl;
	}	
}