#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> bus(n+1);
	vector<bool> visited(n+1, false);
	vector<int> mincost(n+1, INT_MAX);

	for (int i = 0; i < m; i++) {
		int start_city, end_city, cost;
		cin >> start_city >> end_city >> cost;
		bus[start_city].push_back(make_pair(end_city, cost));
	}

	int start, end;
	cin >> start >> end;

	mincost[start] = 0;

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push(make_pair(0, start));

	while(!pq.empty() || !visited[end]) {
		int now = pq.top().second;
		pq.pop();
		if (visited[now])
			continue;
		visited[now] = true;

		for (int i = 0; i < bus[now].size(); i++) {
			int next = bus[now][i].first;
			if (!visited[next]){
				mincost[next] = min(mincost[next], mincost[now] + bus[now][i].second);
				pq.push(make_pair(mincost[next], next));				
			}
		}
	}

	cout << mincost[end];
}