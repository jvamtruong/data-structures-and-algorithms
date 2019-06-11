#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MOD = 1E9 + 7;
const int MAX = 1E5;

long long f[MAX + 5];
long long pref[MAX + 5];

// f[i] : so cach di tu bac 1 den bac i
// f[i] = f[i - 1] + f[i - 2] + .. f[i - k]

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        pref[0] = 1;
        pref[1] = 2;
        f[1] = 1;
        for (int i = 2 ; i <= n; i++) {
            if (i - k - 1 >= 0) f[i] = (pref[i - 1] - pref[i - k - 1]) % MOD;
            else f[i] = pref[i - 1];
            if (f[i] < 0) f[i] += MOD;
            pref[i] = (pref[i - 1] + f[i]) % MOD;

        }
        cout << f[n] << endl;
    }   
}   