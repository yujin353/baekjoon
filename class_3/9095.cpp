#include <iostream>
#include <vector>
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 0; tc < T ; tc++) {
		int n;
		cin >> n;

		vector<int> dp(11, 0);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int k = 4; k <= n; k++) {
			for (int i = 1; i <= 3; i++)
				dp[k] += dp[k-i];
		}

		cout << dp[n] << "\n";
	}
}