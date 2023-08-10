#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;

void preorder(int x) {
	if (x == -1) return;
	char output = x + 'A';
	cout << output;
	preorder(tree[x][0]);
	preorder(tree[x][1]);
}

void inorder(int x) {
	if (x == -1) return;
	inorder(tree[x][0]);
	char output = x + 'A';
	cout << output;
	inorder(tree[x][1]);
}

void postorder(int x) {
	if (x == -1) return;
	postorder(tree[x][0]);
	postorder(tree[x][1]);
	char output = x + 'A';
	cout << output;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	tree.resize(n);
	for (int i = 0; i < n; i++) {
		char p, l, r;
		cin >> p >> l >> r;

		int intp = p - 'A';

		tree[intp].resize(2);

		if (l != '.'){
			int intl = l - 'A';
			tree[intp][0] = intl;
		}
		else 
			tree[intp][0] = -1;

		if (r != '.') {
			int intr = r - 'A';
			tree[intp][1] = intr;
		}
		else
			tree[intp][1] = -1;
	}

	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
}