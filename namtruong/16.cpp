#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

long long power(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long p = power(a, b >> 1);
    if (b & 1) return a * p * p;
    else return p * p;
}

int solve(long long i, int n) {
    long long m = power(2, n);
    if (i == m) return n + 1;
    else {
        if (i < m) return solve(i, n - 1);
        else return solve(i - m, n - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        cout << solve(k, n - 1) << endl;    
    }
}