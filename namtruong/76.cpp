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
        string s;
        cin >> s;
        if (s == "PUSH") {
            int x;
            cin >> x;
            q.push(x);
        }
        if (s == "PRINTFRONT") {
            if (!q.empty()) cout << q.front() << endl;
            else cout << "NONE" << endl;
        }
        if (s == "POP") {
            if (!q.empty()) q.pop();
        }
    }    
}