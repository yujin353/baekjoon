#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> connect(n+1);
	for(int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a>> b;
		connect[a].push_back(b);
		connect[b].push_back(a);
	}
	
	vector<int> parent(n+1);
	vector<bool> visited(n+1, false);
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		visited[now] = true;

		for(int i = 0; i < connect[now].size(); i++) {
			int next = connect[now][i];
			if (visited[next]) continue;
			visited[next] = true;
			parent[next] = now;
			q.push(next);
		}
	}

	for(int i = 2; i <= n; i++)
		cout << parent[i] << "\n";
}