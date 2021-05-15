#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < long long > v;
vector < long long > pw;

long long power(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long p = power(a, b >> 1);
    if (b & 1) return a * p * p;
    else return p * p;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0 ; i < 50; i++) pw.push_back(power(2, i));
    while (t--) {
        long long n, l, r;
        cin >> n >> l >> r;
        v.clear();
        while (n) {
            v.push_back(n);
            n >>= 1;
        }
        int k = v.size() - 1;
        int ans = 0;
        for (long long i = l ; i <= r; i++) {
            if (i & 1) ans++;
            else {
                long long val = i;
                //if (val > power(2, k)) val -= power(2, k);
                while (val & (val - 1)) {
                    int x = upper_bound(pw.begin(), pw.end(), val) - pw.begin() - 1;
                    val -= pw[x];
                }
                ans += v[k - (lower_bound(pw.begin(), pw.end(), val) - pw.begin())] & 1;
            }   
        }
        cout << ans << endl;
    }
}