#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> connect;
vector<bool> visited;
int root, del, leaf = 0;

void bfs() {
	queue<int> q;
	q.push(root);
	
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		visited[now] = true;

		if (now == del) continue;

		if (connect[now].size() == 0)
			leaf++;

		for (int i = 0; i < connect[now].size(); i++) {
			int next = connect[now][i];
			if (next == del && connect[now].size() == 1) leaf++;
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	connect.resize(n);
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		if (tmp == -1)
			root = i;
		else
			connect[tmp].push_back(i);
	}
	cin >> del;

	visited.resize(n, false);
	bfs();
	cout << leaf;
}