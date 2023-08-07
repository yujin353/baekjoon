#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<bool> visited;
vector<vector<int>> connect;
vector<vector<int>> parent;
vector<int> depth;
int maxDepth = 0;

void BFS(int x) {
	queue<int> q;
	q.push(x);
	visited[x] = true;
	parent[x][0] = 0;
	depth[x] = 0;

	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < connect[now].size(); i++) {
			int next = connect[now][i];
			if (visited[next]) continue;
			visited[next] = true;
			parent[1][next] = now;
			depth[next] = depth[now] + 1;
			if (maxDepth < depth[next])
				maxDepth = depth[next];
			q.push(next);
		}

	}
}

int LCA(int a, int b) {
	if (depth[a] > depth[b]){
		int tmp = a;
		a = b;
		b = tmp;
	}

	// 깊이 동일하게 맞추기
	int dif = depth[b] - depth[a];
	if (dif > 0) {
		int k = 0, two = 1;
		while (1) {
			two *= 2;
			if (two > dif)
				break;
			k++;
		}

		b = parent[k+1][b];
	}

	// 조상 찾기
	int k = max(depth[a], depth[a]);
	while(k >= 0 && parent[k][a] == parent[k][b]) {
		k--;
	}
	a = parent[k+1][a];
	b = parent[k+1][b];

	if (a != b)
		return parent[1][a];
	else
		return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;
	
	// 인접 리스트로 트리 데이터 구현
	connect.resize(n+1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		connect[a].push_back(b);
		connect[b].push_back(a);
	}

	parent.resize(n);
	for(int i = 0; i < n; i++)
		parent[i].resize(n+1);
	visited.resize(n+1, false);
	depth.resize(n+1);
	
	// BFS(DFS)로 각 노드 깊이, 2^0번째 부모 구하기
	BFS(1);
	
	// 점화식 이용해 Parent 배열 구하기
	for (int i = 2; i < maxDepth; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i-1][parent[i-1][j]];
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
}