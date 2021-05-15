#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1E6;
const int BASE = 311;

int hashS[MAX + 5];
int pw[MAX + 5];

int getHash(int i, int j) {
	return hashS[j] - hashS[i - 1] * pw[j - i + 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int test;
	cin >> test;
	pw[0] = 1;
	for (int i = 1 ; i <= MAX; i++) {
		pw[i] = pw[i - 1] * BASE;
	}
	while (test--) {
		string s, t;
		cin >> s >> t;
		if (t.length() > s.length()) cout << "NO" << endl;
		else {
			int n = t.length();
			int m = s.length();
			t.insert(0, " ");
			s.insert(0, " ");
			for (int i = 1 ; i <= m; i++) {
				hashS[i] = hashS[i - 1] * BASE + s[i];
			}
			int hashT = 0;
			for (int i = 1 ; i <= n; i++) {
				hashT = hashT * BASE + t[i];
			}
			bool bl = false;
			for (int i = 1 ; i <= m - n + 1; i++) {
				if (getHash(i, i + n - 1) == hashT) {
					cout << "YES" << endl;
					bl = true;
					break;
				}
			}
			if (!bl) cout << "NO" << endl;
		}
	}
}