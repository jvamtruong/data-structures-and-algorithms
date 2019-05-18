#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int x[20];
int n, k;
vector < string > ans;

void process() {
    int idx = -1;
    bool bl = false;
    int cnt = 0;
    for (int i = 1 ; i <= n + 1; i++) {
        if (!bl) {
            if (x[i] == 0) {
                bl = true;
                cnt++;
            }  
        }
        else {
            if (x[i] == 0) cnt++;
            else {
                bl = false;
                if (cnt == k) {
                    idx = i;
                    break;
                }
                cnt = 0;
            }
        }
    }
    if (idx != -1) {
        bl = false;
        cnt = 0;
        for (int i = idx ; i <= n + 1; i++) {
            if (!bl) {
                if (x[i] == 0) {
                    bl = true;
                    cnt++;
                }
            }
            else {
                if (x[i] == 0) cnt++;
                else {
                    bl = false;
                    if (cnt == k) return;
                    cnt = 0;
                }
            }
        }
        string s = "";
        for (int i = 1 ; i <= n; i++) {
            s += ('A' + x[i]);
        }
        ans.push_back(s);
    }
}

void Try(int i) {
    for (int j = 0 ; j <= 1; j++) {
        x[i] = j;
        if (i == n) process();
        else Try(i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    x[n + 1] = -1; 
    Try(1);
    cout << ans.size() << endl;
    for (int i = 0 ; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}