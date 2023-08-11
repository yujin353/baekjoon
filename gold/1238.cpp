#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, x;
	cin >> n >> m >> x;

	vector<vector<int>> time(n+1);
	for (int i = 1; i <= n; i++){
		time[i].resize(n+1, 1000000);
		time[i][i] = 0;
	}

	for(int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		time[a][b] = t;
	}

	for (int k = 1; k <= n; k++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				time[s][e] = min(time[s][e], time[s][k]+time[k][e]);
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(answer, time[i][x] + time[x][i]);
	}
	cout << answer << "\n";
}