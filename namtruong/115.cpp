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

Node *leftMost(Node *root) {
	while (root -> left) root = root -> left;
	return root;
}	

Node *del(Node *root, int val) {
	if (root == NULL) return root;
	if (val < root -> val) root -> left = del(root -> left, val);
	if (val > root -> val) root -> right = del(root -> right, val);
	if (val == root -> val) {
		if (root -> left == NULL) {
			Node *temp = root -> right;
			delete root;
			return temp;
		}
		if (root -> right == NULL) {
			Node *temp = root -> left;
			delete root;
			return temp;
		}
		Node *temp = leftMost(root -> right);
		root -> val = temp -> val;
		root -> right = del(root -> right, root -> val);
	}
	return root;
}

void preOrder(Node *root) {
	if (root) {
		cout << root -> val << " ";
		preOrder(root -> left);
		preOrder(root -> right);
	}
}

void inOrder(Node *root) {
	if (root) {
		inOrder(root -> left);
		cout << root -> val << " ";
		inOrder(root -> right);
	}
}

void postOrder(Node *root) {
	if (root) {
		postOrder(root -> left);
		postOrder(root -> right);
		cout << root -> val << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int type;
	Node *root = NULL;
	while (cin >> type) {
		if (type == 1) {
			int x;
			cin >> x;
			root = insert(root, x);
		}
		if (type == 2) {
			int x;
			cin >> x;
			root = del(root, x);
		}
		if (type == 3) {
			preOrder(root);
			cout << endl;
		}
		if (type == 4) {
			inOrder(root);
			cout << endl;
		}
		if (type == 5) {
			postOrder(root);
			cout << endl;
		}
	}	
}