#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

long long f[100];

char solve(long long i, int n) {
    if (i == 1 && n == 1) return 'A';
    if (i == 1 && n == 2) return 'B';
    if (i > f[n - 2]) return solve(i - f[n - 2], n - 1);
    else return solve(i, n - 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    f[1] = f[2] = 1;
    for (int i = 3 ; i <= 92; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }       
    while (t--) {
        int n;
        long long i;
        cin >> n >> i;
        cout << solve(i, n) << endl;
    }
}