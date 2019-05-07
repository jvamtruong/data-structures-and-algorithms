#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound 
#define div         ___div
#define left        ___left
#define right       ___right
#define bitcount(x) __builtin_popcountll(x)
#define all(x)     x.begin(),x.end()
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> plll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef vector<plll> vlll;
typedef vector<char> vc;
inline ll max(ll a, ll b) {return a < b ? b : a;}
inline ll min(ll a, ll b) {return a < b ? a : b;}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b;a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a * (b / gcd(a, b));}
inline ll fpow(ll a, ll b, ll m) {ll r = 1; while (b) {if (b & 1) r = (r % m) * a % m; a %= m; a = a * a % m; b >>= 1;} return r;}


const int BASE = 311;
const int MAX = 50000;

string s;
string t;
int n;
int pw[MAX + 5];
int hashS[MAX + 5];
int hashT[MAX + 5];
int ans = 1;

int getHashS(int i, int j) {
	return hashS[j] - hashS[i - 1] * pw[j - i + 1];
}

int getHashT(int i, int j) {
	return hashT[j] - hashT[i - 1] * pw[j - i + 1];
}

int odd_lps() {
	int l = 1;
	int r = (n & 1) ? n : n - 1;
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
			if (m & 1) l = m + 1;
			else l = m + 2;
			res = k;
		}
		else r = m - 1;
	}	
	return res;
}

int even_lps() {
	int l = 1;
	int r = (n & 1) ? n - 1 : n;
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
			if (m & 1) l = m + 2;
			else l = m + 1;
			res = k;
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
	while (test--) {
		cin >> s;
		n = s.length();
		t.clear();
		for (int i = n - 1 ; i >= 0; i--) t.push_back(s[i]);
		t.insert(0, " ");
		s.insert(0, " ");
		pw[0] = 1;
		for (int i = 1 ; i <= n; i++) {
			pw[i] = pw[i - 1] * BASE;
			hashS[i] = hashS[i - 1] * BASE + s[i];
			hashT[i] = hashT[i - 1] * BASE + t[i];
		}
		ans = max(odd_lps(), even_lps());
		cout << ans << endl;
	} 	
}