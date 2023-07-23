#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<long long>> sCost(n+1);
	for (int i = 1; i <= n; i++)
		sCost[i].resize(n+1, INT_MAX);

	for (int i = 1; i <= n; i++)
		sCost[i][i] = 0;

	for (int i = 0; i < m; i++) {
		long long s, e, c;
		cin >> s >> e >> c;
		sCost[s][e] = min(sCost[s][e], c);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				sCost[j][k] = min(sCost[j][k], sCost[j][i]+sCost[i][k]);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (sCost[i][j] >= INT_MAX)
				cout << "0 ";
			else
				cout << sCost[i][j] << " ";
		}
        if (i != n)
		    cout << "\n";
	}
}