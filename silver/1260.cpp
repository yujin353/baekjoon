#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> connect;
vector<bool> visited;

void DFS(int x) {
	if (visited[x])
		return;
	visited[x] = true;
	cout << x << " ";

	for (long i = 0; i < connect[x].size(); i++) {
		int next = connect[x][i];
		if (visited[next] == false)
			DFS(next);
	}
}

void BFS(int x) {
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		visited[now] = true;
		cout << now << " ";

		for (long i = 0; i < connect[now].size(); i++) {
			int next = connect[now][i];
			if (visited[next] == false) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, s;
	cin >> n >> m >> s;

	connect.resize(n+1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		connect[u].push_back(v);
		connect[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		sort(connect[i].begin(), connect[i].end());
	
	visited.resize(n+1, false);
	DFS(s);
	cout << "\n";
	for (int i = 1; i <= n; i++)
		visited[i] = false;
	BFS(s);
	cout << "\n";
}