#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

deque < int > dq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s == "PUSHBACK") {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        if (s == "PUSHFRONT") {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        if (s == "POPBACK") {
            if (!dq.empty()) dq.pop_back();
        }
        if (s == "POPFRONT") {
            if (!dq.empty()) dq.pop_front();
        }
        if (s == "PRINTBACK") {
            if (!dq.empty()) cout << dq.back() << endl;
            else cout << "NONE" << endl;
        }
        if (s == "PRINTFRONT") {
            if (!dq.empty()) cout << dq.front() << endl;
            else cout << "NONE" << endl;
        }
    }    
}