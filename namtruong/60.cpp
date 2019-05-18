#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < char > v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        v.clear();
        bool bl = false;
        for (int i = 0 ; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') v.push_back(s[i]);
            if (s[i] == ')') {
                if (v.empty()) {
                    bl = true;
                    break;
                }
                else {
                    if (v.back() != '(') {
                        bl =  true;
                        break;
                    }
                    else v.pop_back();
                }
            }
            if (s[i] == ']') {
                if (v.empty()) {
                    bl = true;
                    break;
                }
                else {
                    if (v.back() != '[') {
                        bl = true;
                        break;
                    }
                    else v.pop_back();
                }
            }
            if (s[i] == '}') {
                if (v.empty()) {
                    bl = true;
                    break;
                }
                else {
                    if (v.back() != '{') {
                        bl = true;
                        break;
                    }
                    else v.pop_back();
                }
            }
        }
        if (bl) {
            cout << "NO" << endl;
            continue;
        }
        if (!v.empty()) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}