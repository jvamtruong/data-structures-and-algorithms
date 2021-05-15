#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

map < string, int > Map;
map < string, int > :: iterator it;
string str;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> str) {
		Map[str]++;
	}	
	cout << Map.size() << endl;
	for (it = Map.begin() ; it != Map.end(); it++) {
		cout << it -> first << " " << it -> second << endl;
	}
}