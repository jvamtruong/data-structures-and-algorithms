#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

map < int, int > Map;
map < int, int > :: reverse_iterator it;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	cin.ignore();	
	while (t--) {
		Map.clear();
		string s;
		getline(cin, s);
		string p;
		getline(cin, p);
		int val = 0;
		int deg = 0;
		s += ' ';
		p += ' ';
		bool bl = false;
		for (int i = 0 ; i < s.length(); i++) {
			if (s[i] == ' ') {
				Map[deg] += val;
				val = deg = 0;
				bl = false;
				continue;
			}
			if (s[i] != '*') {
				if (!bl) {
					if (s[i] >= '0' && s[i] <= '9') val = val * 10 + (s[i] -'0');
				}
			}
			else bl = true;
			if (bl) {
				if (s[i] >= '0' && s[i] <= '9') deg = deg * 10 + (s[i] - '0');
			}
		}
		val = deg = 0;
		bl = false;
		for (int i = 0 ; i < p.length(); i++) {
			if (p[i] == ' ') {
				Map[deg] += val;
				deg = val = 0;
				bl = false;
				continue;
			}
			if (p[i] != '*') {
				if (!bl) {
					if (p[i] >= '0' && p[i] <= '9') val = val * 10 + (p[i] - '0');
				}
			}
			else bl = true;
			if (bl) {
				if (p[i] >= '0' && p[i] <= '9') deg = deg * 10 + (p[i] - '0');
			}
		}
		int cnt = 0;
		for (it = Map.rbegin() ; it != Map.rend(); it++) {
			cnt++;
			cout << it -> second << "*x^" << it -> first;
			if (cnt < Map.size()) cout << " " << "+" << " ";
		}
		cout << endl;
	}
}