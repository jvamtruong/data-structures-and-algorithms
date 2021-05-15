#include<bits/stdc++.h>
#define endl '\n'
using namespace std;




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int stt;
        string s;
        cin >> stt >> s;
        cout << stt << " ";
        if (!next_permutation(s.begin(), s.end())) cout << "BIGGEST" << endl;
        else cout << s << endl;
    }   
}