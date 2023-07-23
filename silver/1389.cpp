#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<long long>> user(n+1);
	for(int i = 1; i <= n; i++)
		user[i].resize(n+1, INT_MAX);

	for (int i = 1; i <= n; i++)
		user[i][i] = 0;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		user[a][b] = 1;
		user[b][a] = 1;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++) {
				user[j][k] = min(user[j][k], user[j][i]+user[i][k]);
			}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> accum;
	for (int i = 1; i <= n; i++){
		int tmp = 0;
		for (int j = 1; j <= n; j++)
			tmp += user[i][j];
		accum.push(make_pair(tmp, i));
	}

	cout << accum.top().second << "\n";
}