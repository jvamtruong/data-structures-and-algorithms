#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < int > v;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		if (s == "PUSH") {
			int x;
			cin >> x;
			v.push_back(x);
		}
		if (s == "POP") {
			if (!v.empty()) v.pop_back();
		}
		if (s == "PRINT") {
			if (v.empty()) cout << "NONE" << endl;
			else cout << v.back() << endl;
		}
	}
}