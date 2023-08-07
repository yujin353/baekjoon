#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int size = 1;
	while(size <= n) {
		size *= 2;
	}
	size *= 2;

	vector<long long> num(size);
	for (int i = 0; i < n; i++)
		cin >> num[i + size/2]; //leaf node 채우기
	// nonleaf 채우기
	for (int i = size/2-1; i > 0; i--)
		num[i] = num[2*i] + num[2*i+1];

	m += k;
	for (int i = 0; i < m; i++) {
		long long a,b,c;
		cin >> a >> b >> c;

		if (a == 1) { // update
			int segNode = b + size/2 - 1;
			long long dif = c - num[segNode];
			while (segNode >= 1) {
				num[segNode] += dif;
				segNode /= 2;
			}
		}
		else { // 구간합
			int start = b + size/2 - 1;
			int end = c + size/2 -1;
			long long sum = 0;
			while (start <= end) {
				if (start % 2 == 1)
					sum += num[start];
				if (end % 2 == 0)
					sum += num[end];
				start = (start + 1) / 2;
				end = (end - 1) / 2;
			}
			cout << sum << "\n";
		}
	}
}