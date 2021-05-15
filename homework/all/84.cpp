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
        vector < int > v;
        for (int i = 1 ; i <= n; i++) {
            int k = i;
            v.clear();
            while (k) {
                v.push_back(k & 1);
                k >>= 1;
            }
            for (int i = v.size() - 1 ; i >= 0; i--) {
                cout << v[i];
            }
            cout << " ";
        }
        cout << endl;
    }    
}