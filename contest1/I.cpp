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
int ope[100];
int mark[100];
ll a[100];
bool ans = false;

bool i_cant_tell_when_the_journey_will_end() {
    ll val;
    if (ope[1] == 1) val = a[x[1]] + a[x[2]];
    if (ope[1] == 2) val = a[x[1]] - a[x[2]]; 
    if (ope[1] == 3) val = a[x[1]] * a[x[2]];
    for (int i = 3 ; i <= 5; i++) {
        if (ope[i - 1] == 1) val += a[x[i]];
        if (ope[i - 1] == 2) val -= a[x[i]];
        if (ope[i - 1] == 3) val *= a[x[i]];
    }
    return val == 23;
}

void guided_by_a_beating_heart(int i) {
    for (int j = 1 ; j <= 3; j++) {
        ope[i] = j;
        if (i == 4) ans |= i_cant_tell_when_the_journey_will_end();
        else guided_by_a_beating_heart(i + 1);
    }
}

void feeling_my_way_through_the_darkness(int i) {
    for (int j = 1 ; j <= 5; j++) {
        if (!mark[j]) {
            x[i] = j;
            mark[j] = true;
            if (i == 5) guided_by_a_beating_heart(1);
            else feeling_my_way_through_the_darkness(i + 1);
            mark[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 1 ; i <= 5; i++) {
            cin >> a[i];
        }
        ans = false;
        feeling_my_way_through_the_darkness(1);
        cout << (ans ? "YES" : "NO") << endl;
    }
}