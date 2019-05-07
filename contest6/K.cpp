#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int BASE = 311;
const int MAX = 1E5;

int hashS[MAX + 5];
int hashT[MAX + 5];
int pw[MAX + 5];
int n;

int getHashS(int i, int j) {
	return hashS[j] - hashS[i - 1] * pw[j - i + 1];
}

int getHashT(int i, int j) {
	return hashT[j] - hashT[i - 1] * pw[j - i + 1];
}

int odd_lps() {
	int l = 1;
	int r = n;
	int res = 1;
	while (l <= r) {
		int m = l + r >> 1;
		int k = (m & 1) ? m : m + 1;
		bool bl = false;
		for (int i = 1 ; i <= n - k + 1; i++) {
			int j = i + k - 1;
			if (getHashS(i, j) == getHashT(n - j + 1, n - i + 1)) {
				bl = true;
				break;
			}
		}
		if (bl) {
			res = k;
			l = k + 1;
		}
		else r = m - 1;
	}
	return res;
}

int even_lps() {
	int l = 1;
	int r = n;
	int res = 1;
	while (l <= r) {
		int m = l + r >> 1;
		int k = (m & 1) ? m + 1 : m;
		bool bl = false;
		for (int i = 1 ; i <= n - k + 1; i++) {
			int j = i + k - 1;
			if (getHashS(i, j) == getHashT(n - j + 1, n - i + 1)) {
				bl = true;
				break;
			}
		}
		if (bl) {
			res = k;
			l = k + 1;
		}
		else r = m - 1;
	}
	return res;
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
		string s;
		cin >> s;
		string t = "";
		n = s.length();
		for (int i = n - 1 ; i >= 0; i--) t += s[i];
		s.insert(0, " ");
		t.insert(0, " ");
		for (int i = 1 ; i <= n; i++) {
			hashS[i] = hashS[i - 1] * BASE + s[i];
			hashT[i] = hashT[i - 1] * BASE + t[i];
		}
		cout << max(odd_lps(), even_lps()) << endl;
	}		
}