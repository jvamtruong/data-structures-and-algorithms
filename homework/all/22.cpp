#include<bits/stdc++.h>
#define endl '\n'
using namespace std;




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1 ; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (i % 2 == 0) ans++;
                int j = n / i;
                if (j != i && j % 2 == 0) ans++;
            }
        }
        cout << ans << endl;
    }   
}