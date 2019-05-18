#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < long long > v;
int x[100];

void process() {
    long long val = 0;
    for (int i = 1 ; i <= 19; i++) {
        val = val * 10 + x[i];
    }
    if (val) v.push_back(val);
}

void Try(int i) {
    for (int j = 0 ; j <= 1; j++) {
        x[i] = j;
        if (i == 19) process();
        else Try(i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    Try(1);
    while (t--) {
        long long n;
        cin >> n;
        cout << upper_bound(v.begin(), v.end(), n) - v.begin() << endl;
    }
}