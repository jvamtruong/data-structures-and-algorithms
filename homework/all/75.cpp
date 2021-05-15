#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

queue < int > q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        while (!q.empty()) q.pop();
        while (n--) {
            int type;
            cin >> type;
            if (type == 1) cout << q.size() << endl;
            if (type == 2) cout << (q.empty() ? "YES" : "NO") << endl;
            if (type == 3) {
                int x;
                cin >> x;
                q.push(x);
            }
            if (type == 4) {
                if (!q.empty()) q.pop();
            }
            if (type == 5) {
                if (!q.empty()) cout << q.front() << endl;
                else cout << -1 << endl;
            }
            if (type == 6) {    
                if (!q.empty()) cout << q.back() << endl;
                else cout << -1 << endl;
            }
        }
    }
}   