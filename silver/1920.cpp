#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;

void binary_search(int s, int e, int x) {
	if (s > e){
		cout << 0 << "\n";
		return;
	}

	int mid = (s+e)/2;
	
	if (num[mid] == x){
		cout << 1 << "\n";
		return;
	}
	else if (num[mid] < x)
		binary_search(mid+1, e, x);
	else
		binary_search(s, mid-1, x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num.begin(), num.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int find;
		cin >> find;
		binary_search(0, n-1, find);
	}
}