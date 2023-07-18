#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> preSum;
	preSum.resize(n+1);
	for (int i = 0; i <= n; i++)
		preSum[i].resize(n+1);

	int tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + tmp;
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << preSum[x2][y2] - (preSum[x2][y1-1] + preSum[x1-1][y2] - preSum[x1-1][y1-1]) << "\n";
	}
}