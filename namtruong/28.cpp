#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int n = 0;
    int m = 0;
    for (int i = 0 ; i < a.length(); i++) {
        if (a[i] == '6') a[i] = '5';
        n = n * 10 + (a[i] - '0');
    }
    for (int i = 0 ; i < b.length(); i++) {
        if (b[i] == '6') b[i] = '5';
        m = m * 10 + (b[i] - '0');
    }
    cout << n + m << " ";
    n = m = 0;
    for (int i = 0 ; i < a.length(); i++) {
        if (a[i] == '5') a[i] = '6';
        n = n * 10 + (a[i] - '0');
    }
    for (int i = 0 ; i < b.length(); i++) {
        if (b[i] == '5') b[i] = '6';
        m = m * 10 + (b[i] - '0');
    }
    cout << n + m;
}