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

	vector<pair<int, int>> cns(n+1);
	for (int i = 1; i <= n; i++) {
		int t, p;
		cin >> t >> p;
		cns[i] = make_pair(t,p);
	}

	vector<pair<int, int>> dp(n+2, make_pair(0,0)); // 남은 날짜, 수입
	for (int i = n; i > 0; i--) {
		if (i + cns[i].first - 1 <= n && i != n)
			dp[i].second = max(dp[i + cns[i].first].second + cns[i].second, dp[i+1].second);
		if (i == n && cns[i].first == 1)
			dp[i].second = cns[i].second;
		//cout << dp[i].second << "\n";
	}
	cout << dp[1].second;
}