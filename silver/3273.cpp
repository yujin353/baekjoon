#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num.begin(), num.end());

	int x;
	cin >> x;

	int s = 0, e = n-1, cnt = 0;
	while(s < e) {
		if (num[s] + num[e] == x){
			cnt++;
			s++;
		}
		else if (num[s] + num[e] < x) {
			s++;
		}
		else
			e--;
	}
	cout << cnt;
}