#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;
typedef pair<int, int> edge;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K;
	cin >> V >> E >> K;

	vector<vector<edge>> connect(V+1);
	for (int i = 0; i < E; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		connect[u].push_back(make_pair(v, w));
	}

	vector<bool> visited(V+1, false);
	vector<int> distance(V+1, INT_MAX);
	distance[K] = 0;

	priority_queue<edge, vector<edge>, greater<edge>> q; // queue가 아닌 priority queue로 해야 시간초과 안남
	q.push(make_pair(0,K));
	while(!q.empty()) {
		int now = q.top().second;
		q.pop();
		if (visited[now])
			continue;
		visited[now] = true;

		for (int i = 0; i < connect[now].size(); i++) {
			int next = connect[now][i].first;
			if (visited[next] == false) {
				distance[next] = min(distance[next], distance[now] + connect[now][i].second);
				q.push(make_pair(distance[next], next));
			}
		}
	}
	for (int i = 1; i <= V; i++){
		if (distance[i] == INT_MAX)
			cout << "INF" << "\n";
		else
			cout << distance[i] << "\n";
	}
}