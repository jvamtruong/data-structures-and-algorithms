#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int x[20];
int n, k;

void printRes() {
    int cnt = 0;
    for (int i = 1 ; i <= n; i++) {
        cnt += x[i];
    }
    if (cnt == k) {
        for (int i = 1 ; i <= n; i++) {
            cout << x[i];
        }
        cout << endl;
    }
}

void Try(int i) {
    for (int j = 0 ; j <= 1; j++) {
        x[i] = j;
        if (i == n) printRes();
        else Try(i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        Try(1);
    }        
}