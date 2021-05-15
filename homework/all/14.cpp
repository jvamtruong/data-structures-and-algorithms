#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MOD = 1E9 + 7;

long long power(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a % MOD;
    long long p = power(a, b >> 1);
    if (b & 1) return a * p % MOD * p % MOD;
    else return p * p % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << power(n, k) << endl;
    }        
}