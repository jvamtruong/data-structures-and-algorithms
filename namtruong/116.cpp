#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

map < string, int > Map;
map < string, int > :: iterator it;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while (cin >> s) Map[s]++;
	cout << Map.size() << endl;
	for (it = Map.begin() ; it != Map.end(); it++) {
		cout << it -> first << " " << it -> second << endl;
	}
}