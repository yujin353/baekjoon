#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int k = 1;
	while (k < n) {
		k *= 2;
	}
	k *= 2;

	vector<int> MIN(k, INT_MAX);
	vector<int> MAX(k, 0);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		MIN[i + k/2] = tmp;
		MAX[i + k/2] = tmp;
	}

	for (int i = k/2 - 1; i >= 0; i--) {
		MIN[i] = min(MIN[i*2], MIN[i*2+1]);
		MAX[i] = max(MAX[i*2], MAX[i*2+1]);
	}

	for (int i = 0; i < m; i++) {
		int start, end, minN = INT_MAX, maxN = 0;
		cin >> start >> end;

		int s = start + k/2 - 1;
		int e = end + k/2 - 1;

		while(s <= e) {
			if (s % 2 == 1) {
				minN = min(minN, MIN[s]);
				maxN = max(maxN, MAX[s]);
				s++;
			}
			if (e % 2 == 0) {
				minN = min(minN, MIN[e]);
				maxN = max(maxN, MAX[e]);
				e--;
			}
			s /= 2;
			e /= 2;
		}

		cout << minN << " " << maxN << "\n";
	}
}