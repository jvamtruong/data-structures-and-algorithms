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


int x[100];
int n, k;
int ans = 0;

bool check() {
    int cnt1 = 1;
    int pos = -1;
    x[n + 1] = 1;
    int i = 1;
    while (i <= n) {
        if (x[i] == 0) {
            cnt1 = 1;
            int j = i + 1;
            while (j <= n && x[j] == 0) {
                cnt1++;
                j++;
            }
            if (cnt1 == k) {
                pos = j + 1;
                break;
            }
            i = j;
        }
        else i++;
    }
    if (pos == -1) return false;
    while (pos <= n) {
        if (x[pos] == 0) {
            int cnt2 = 1;
            int j = pos + 1;
            while (j <= n && x[pos] == 0) {
                cnt2++;
                j++;
            }
            if (cnt2 == cnt1) {
                return false;
            }
            pos = j;
        }
        else pos++;
    }
    return true;
}

void printRes() {
    for (int i = 1 ; i <= n; i++) {
        cout << (x[i] ? 'B' : 'A');
    }
    cout << endl;
}

void Try(int i) {
    for (int j = 0 ; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            if (check()) ans++;
        }
        else Try(i + 1);
    }
}

void _Try(int i) {
    for (int j = 0 ; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            if (check()) printRes();
        }
        else _Try(i + 1);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    Try(1);
    cout << ans << endl;
    _Try(1);
}