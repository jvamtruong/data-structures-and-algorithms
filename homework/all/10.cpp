#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, s;
int x[35];
int a[35];
long long sum[35];
int cnt[35];
int ans = INT_MAX;

void Try(int i) {
    for (int j = 0 ; j <= 1; j++) {
        x[i] = j;
        sum[i] = sum[i - 1] + a[i] * j;
        cnt[i] = cnt[i - 1] + j;
        if (cnt[i] < ans) {
            if (i == n) {
                if (sum[i] == s) {
                    ans = min(ans, cnt[i]);
                }
            }
            else Try(i + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1 ; i <= n; i++) {
        cin >> a[i];
    }    
    Try(1);
    cout << ans;
}