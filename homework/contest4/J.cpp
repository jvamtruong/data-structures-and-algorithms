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
		string a;
		cin >> a;
		string s = "";
		string x = "";
		vector < char > v;
		v.clear();
		for (int i = 0 ; i < a.length(); i++) {
			if (a[i] == '(' || a[i] == ')' || a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
				s += ' ';
				s += a[i];
				s += ' ';
				continue;
			}
			s += a[i];
		}
		bool bl = false;
		for (int i = 0 ; i < s.length(); i++) {
			if (s[i] == ' ') {
				if (bl) {
					bl = false;
					x += ' ';
				}
			}
			if (s[i] == '(') v.push_back(s[i]);
			if (s[i] == ')') {
				while (!v.empty() && v.back() != '(') {
					x += v.back();
					v.pop_back();	
				}
				v.pop_back();
			}
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
				while (!v.empty() && prior(v.back()) >= prior(s[i])) {
					x += v.back();
					v.pop_back();
				}
				v.push_back(s[i]);
			}
			if (s[i] >= '0' && s[i] <= '9') {
				if (!bl) {
					bl = true;
				}
				x += s[i];
			}
		}
		while (!v.empty()) {
			x += v.back();
			v.pop_back();
		}
		vector < long long > e;
		e.clear();
		s.clear();
		for (int i = 0 ; i < x.length(); i++) {
			if (x[i] == '+' || x[i] == '-' || x[i] == '*' || x[i] == '/') {
				s += ' ';
				s += x[i];
				s += ' ';
				continue;
			}
			s += x[i];
		}
		bl = false;
		long long val = 0;
		//cout << s << endl;
		s += ' ';
		for (int i = 0 ; i < s.length(); i++) {
			if (s[i] == ' ') {
				if (bl) e.push_back(val);
				val = 0;
				bl = false;
			}
			if (s[i] >= '0' && s[i] <= '9') {
				bl = true;
				val = val * 10 + (s[i] - '0');
			}
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
				long long x = e.back();
				e.pop_back();
				long long y = e.back();
				e.pop_back();
				if (s[i] == '+') e.push_back(y + x);
				if (s[i] == '-') e.push_back(y - x);
				if (s[i] == '*') e.push_back(y * x);
				if (s[i] == '/') e.push_back(y / x);
			}
		}
		if (!e.empty()) cout << e.back() << endl;
	}	
}