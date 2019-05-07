#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < int > v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int x;
	while (cin >> s) {
		if (s == "push") {
			cin >> x;
			v.push_back(x);
		}
		if (s == "pop") v.pop_back();
		if (s == "show") {
			if (v.empty()) cout << "empty" << endl;
			else {
				for (int i = 0 ; i < v.size(); i++) {
					cout << v[i] << " ";
				}
				cout << endl;
			}
		}
	}	
}