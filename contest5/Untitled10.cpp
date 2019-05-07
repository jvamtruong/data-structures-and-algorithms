#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

//---------------------------------WA------------------------------------------//s

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
		if (i == 0) {
			ans.push_back(a[i]);
			cout << "Buoc " << i << ":" << " " << ans.back() << endl;
			continue;
		}
		ans.push_back(a[i]);
		sort(ans.begin(), ans.end());
		cout << "Buoc " << i << ":" << " ";
		for (int j = 0 ; j < ans.size(); j++) {
			cout << ans[j] << " ";
		}
		cout << endl;
	}
}
