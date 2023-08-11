#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n, k, w;
		cin >> n >> k;

		vector<int> D(n+1);
		for (int i = 1; i <= n; i++)
			cin >> D[i];

		vector<vector<int>> connect(n+1);
		vector<int> pointed(n+1,0);
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			connect[x].push_back(y);
			pointed[y]++;
		}

		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		for (int i = 1; i<= n; i++)
			if (pointed[i] == 0)
				pq.push(make_pair(0,i));

		vector<int> tot(n+1, 0);
		cin >> w;
		while(!pq.empty()) {
			if (pointed[w] == 0)
				break;

			int nowD = pq.top().first;
			int now = pq.top().second;
			pq.pop();

			for (int i = 0; i < connect[now].size(); i++) {
				int next = connect[now][i];
				pointed[next]--;
				tot[next] = max(tot[next], nowD + D[now]);
				if (pointed[next] == 0) {
					pq.push(make_pair(tot[next], next));
				}
			}
		}
		cout << tot[w] + D[w] << "\n";
	}
}