#include<bits/stdc++.h>
#define endl '\n'
using namespace std;




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector < int > a(n + 5);
        int ans = -1;
        for (int i = 1 ; i <= n; i++) {
            cin >> a[i];
            if (a[i] == k) {
                if (ans == -1) ans = i;
            }
        }
        if (ans == -1) cout << "NO" << endl;
        else cout << ans << endl;
    }    
}