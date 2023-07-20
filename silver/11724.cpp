#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> connect;
vector<bool> visited;
void DFS(int x) {
	if (visited[x] == true)
		return;
	visited[x] = true;

	for (int i = 0; i < connect[x].size(); i++) {
		int next = connect[x][i];
		if (visited[next] == false)
			DFS(next);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	connect.resize(n+1);
	for (int i = 0; i < m; i++) {
		int u,v;
		cin >> u >> v;
		connect[u].push_back(v);
		connect[v].push_back(u);
	}

	visited.resize(n+1, false);
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			DFS(i);
			answer++;
		}
	}
	cout << answer;
}