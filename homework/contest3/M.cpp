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


int n;
int ans = INT_MAX;
int x[15];
int cnt[15][30];
bool mark[15];
string s[15];

void process() {
	int res = 0;
	for (int i = 1 ; i < n; i++) {
		for (int j = 0 ; j < 26; j++) {
			if (cnt[x[i]][j] && cnt[x[i + 1]][j]) res++;
		}
	}
	ans = min(ans, res);
}

void Try(int i) {
	for (int j = 1 ; j <= n; j++) {
		if (!mark[j]) {
			x[i] = j;
			mark[j] = true;
			if (i == n) process();
			else Try(i + 1);
			mark[j] = false;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n; i++) {
    	cin >> s[i];
    	for (int j = 0 ; j < s[i].length(); j++) {
    		cnt[i][s[i][j] - 'A']++;
    	}
    }
    Try(1);
    cout << ans;
}	