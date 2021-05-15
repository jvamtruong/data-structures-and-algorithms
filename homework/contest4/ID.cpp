#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


int prior(char ch) {
	if (ch == '*' || ch == '/') return 2;
	if (ch == '+' || ch == '-') return 1;
	if (ch == '(') return 0;
}

string convert(string s) {
	string x = "";
	for (int i = 0 ; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			x[i] += ' ';
			x[i] += s[i];
			x[i] += ' ';
			continue;
		}
		x[i] += s[i];
	}
	string postfix = "";
	vector < char > v;
	v.clear();
	bool bl = false;
	for (int i = 0 ; i < x.length(); i++) {
		if (x[i] == ' ' ) {
			if (bl) {
				bl = false;
				postfix += ' ';
			}
		}
		if (x[i] == '(') v.push_back(x[i]);
		if (x[i] == ')') {
			while (!v.empty() && v.back() != '(') {
				postfix += v.back();
				v.pop_back();
			}
			v.pop_back();
		}
		if (x[i] == '+' || x[i] == '-' || x[i] == '*' || x[i] == '/') {
			while (!v.empty() && prior(v.back()) >= prior(x[i])) {
				postfix += v.back();
				v.pop_back();
			}
			v.push_back(x[i]);
		}
		if (x[i] >= '0' && x[i] <= '9') {
			if (!bl) bl = true;
			postfix += x[i];
		}
	}
	while (!v.empty()) {
		postfix += v.back();
		v.pop_back();
	}
	//cout << postfix << endl;
	return postfix;
}

int main() {
	ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string t = "";
		for (int i = 0 ; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
				t += ' ';
				t += s[i];
				t += ' ';
				continue;
			}
			t += s[i];
		}
		vector < char > e;
		e.clear();
		bool ok = false;
		string p = "";
		for (int i = 0 ; i < t.length(); i++) {
			if (t[i] == ' ') {
				if (ok) {
					ok = false;
					p += ' ';
				} 
			}
			if (t[i] == '(') e.push_back(t[i]);
			if (t[i] == ')') {
				while (!e.empty() && e.back() != '(') {
					p += e.back();
					e.pop_back();
				}
				e.pop_back();
			}
			if (t[i] == '+' || t[i] == '-' || t[i] == '*' || t[i] == '/') {
				while (!e.empty() && prior(e.back()) >= prior(t[i])) {
					p += e.back();
					e.pop_back();
				}
				e.push_back(t[i]);
			}
			if (t[i] >= '0' && t[i] <= '9') {
				ok = true;
				p += t[i];
			}
		}
		while (!e.empty()) {
			p += e.back();
			e.pop_back();
		}
		//cout << p << endl;
		string ans = "";
		for (int i = 0 ; i < p.length(); i++) {
			if (p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/') {
				ans += ' ';
				ans += p[i];
				ans +=  ' ';
				continue;
			}
			ans += p[i];
		}
		vector < long long > v;
		v.clear();
		long long val = 0;
		bool bl = false;
		ans += ' ';
		for (int i = 0 ; i < ans.length(); i++) {
			if (ans[i] == ' ') {
				if (bl) {
					v.push_back(val);
				}
				bl = false;
				val = 0;
			}
			if (ans[i] >= '0' && ans[i] <= '9') {
				bl = true;
				val = val * 10 + (ans[i] - '0');
			}
			if (ans[i] == '+' || ans[i] == '-' || ans[i] == '*' || ans[i] == '/') {
				long long x = v.back();
				v.pop_back();
				long long y = v.back();
				v.pop_back();
				if (ans[i] == '+') v.push_back(y + x);
				if (ans[i] == '-') v.push_back(y - x);
				if (ans[i] == '*') v.push_back(y * x);
				if (ans[i] == '/') v.push_back(y / x);
			}
		}
		if (!v.empty()) cout << v.back() << endl;
	}		
}