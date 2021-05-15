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
        string temp = "";
        for (int i = 0 ; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                temp += ' ';
                temp += s[i];
                temp += ' ';
            }
            else temp += s[i];
        }
        temp += ' ';
        string postfix = "";
        bool bl = false;
        for (int i = 0 ; i < temp.length(); i++) {
            if (temp[i] == ' ') {
                if (bl) {
                    postfix += ' ';
                    bl = false;
                } 
            }
            if (temp[i] == '(') v.push_back('(');
            if (temp[i] == ')') {
                while (!v.empty() && v.back() != '(') {
                    postfix += v.back();
                    postfix +=  ' ';
                    v.pop_back();
                }
                v.pop_back();
            }
            if (temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/') {
                while (!v.empty() && prior(v.back()) >= prior(temp[i])) {
                    postfix += v.back();
                    postfix += ' ';
                    v.pop_back();
                }
                v.push_back(temp[i]);
            }
            if (temp[i] >= '0' && temp[i] <= '9') {
                bl = true;
                postfix += temp[i];
            }
        }
        while (!v.empty()) {
            postfix += v.back();
            v.pop_back();
        }
        postfix += ' ';
        vector < long long > cal;
        cal.clear();
        int val = 0;
        bl = false;
        for (int i = 0 ; i < postfix.length(); i++) {
            if (postfix[i] == ' ') {
                if (bl) {
                    cal.push_back(val);
                    val = 0;
                    bl = false;
                }
            }
            if (postfix[i] >= '0' && postfix[i] <= '9') {
                bl = true;
                val = val * 10 + (postfix[i] - '0');
            }
            if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
                char ch = postfix[i];
                long long y = cal.back();
                cal.pop_back();
                long long x = cal.back();
                cal.pop_back();
                if (ch == '+') cal.push_back(x + y);
                if (ch == '-') cal.push_back(x - y);
                if (ch == '*') cal.push_back(x * y);
                if (ch == '/') cal.push_back(x / y);
            }
        }
        if (!cal.empty()) cout << cal.back() << endl;
    }
}