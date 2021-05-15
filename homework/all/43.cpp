#include<bits/stdc++.h>
#define endl '\n'
using namespace std;




int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector < int > a(n + 5);
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
	}	
	vector < int > ans;
	for (int i = 0 ; i < n; i++) {
		ans.push_back(a[i]);
		sort(ans.begin(), ans.end());
		cout << "Buoc " << i << ": ";
		for (int j = 0 ; j < ans.size(); j++) {
			cout << ans[j] << " ";
		}
		cout << endl;
	}
}