#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < char > v;

int prior(char ch) {
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    if (ch == '(') return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        v.clear();
        string ans = "";
        for (int i = 0 ; i < s.length(); i++) {
            if (s[i] == '(') v.push_back('(');
            if (s[i] == ')') {
                while (!v.empty() && v.back() != '(') {
                    ans += v.back();
                    v.pop_back();
                }
                v.pop_back();
            }
            if (s[i] >= 'a' && s[i] <= 'z') ans += s[i];
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                while (!v.empty() && prior(v.back()) >= prior(s[i])) {
                    ans += v.back();
                    v.pop_back();
                }
                v.push_back(s[i]);
            }
        }
        while (!v.empty()) {
            ans += v.back();
            v.pop_back();
        }
        cout << ans << endl;
    }    
}