#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<int> M;
vector<vector<long long>> dp;

int execute(int s, int e) {
	if (dp[s][e] != -1) return dp[s][e];
	
	if (s == e) return 0;
	
	if (e - s == 1)
		return M[s-1] * M[s] * M[e];

	int result = INT_MAX;
	for (int i = s; i < e; i++) {
		result = min(result, M[s-1] * M[i] * M[e] + execute(s,i) + execute(i+1, e));
	}

	return dp[s][e] = result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, tmp;
	cin >> n;

	M.resize(n+1);
	cin >> M[0] >> M[1];
	for (int i = 2; i <= n; i++) 
		cin >> tmp >> M[i];

	dp.resize(n+1);
	for (int i = 0; i <= n; i++){
		dp[i].resize(n+1, -1);
	}

	cout << execute(1, n) << "\n";
}