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





int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 	string a, b;
 	cin >> a >> b;
 	int x = 0;
 	int y = 0;
 	for (int i = 0 ; i < a.length(); i++) {
 		if (a[i] == '6') x = x * 10 + 5;
 		else x = x * 10 + (a[i] - '0');
 	}   
 	for (int i = 0 ; i < b.length(); i++) {
 		if (b[i] == '6') y = y * 10 + 5;
 		else y = y * 10 + (b[i] - '0');
 	}
 	int res1 = x + y;
 	x = 0;
 	y = 0;
 	for (int i = 0 ; i < a.length(); i++) {
 		if (a[i] == '5') x = x * 10 + 6;
 		else x = x * 10 + (a[i] - '0');
 	}
 	for (int i = 0 ; i < b.length(); i++) {
 		if (b[i] == '5') y = y * 10 + 6;
 		else y = y * 10 + (b[i] - '0');
 	}
 	int res2 = x + y;
 	cout << res1 << " " << res2;
}