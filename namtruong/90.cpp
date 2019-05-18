#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

set < pair < int, int > > s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 1 ; i <= n; i++) {
        string str;
        getline(cin, str);
        str += ' ';
        int val = 0;
        for (int j = 0 ; j < str.length(); j++) {
            if (str[j] == ' ' ) {
                s.insert(make_pair(min(i, val), max(i, val)));
                val = 0;
            } 
            else val = val * 10 + (str[j] - '0');
        }   
    }
    for (auto it : s) {
        cout << it.first << " " << it.second << endl;
    }
}