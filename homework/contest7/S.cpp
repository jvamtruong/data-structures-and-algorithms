#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	int val;
	Node *left, *right;
	Node(int V) {
		val = V;
		left = right = NULL;
	}
};

Node *insert(Node *root, int val) {
	if (root == NULL) return new Node(val);
	if (val < root -> val) root -> left = insert(root -> left, val);
	else root -> right = insert(root -> right, val);
	return root;
}

int height(Node *root) {
	if (root == NULL) return 0;
	if (root) {
		if (root -> left == NULL && root -> right == NULL) return 1;
		return max(height(root -> left), height(root -> right)) + 1;
	}
}

void preOrder(Node *root) {
	if (root) {
		cout << root -> val << " ";
		preOrder(root -> left);
		preOrder(root -> right);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		Node *root = NULL;
		for (int i = 0 ; i < n; i++) {
			int x;
			cin >> x;
			root = insert(root, x);
		}
		//preOrder(root);
		//cout << endl;
		cout << height(root) - 1 << endl;
	}	
}