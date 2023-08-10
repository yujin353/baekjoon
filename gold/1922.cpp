#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> parent;

int find(int x) {
	if (x == parent[x])
		return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<tuple<int, int, int>> edge;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back(make_tuple(c, a, b));
	}
	sort(edge.begin(), edge.end());

	parent.resize(n+1);
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	int connect = 0, i = 0, cost = 0;
	while (connect < n-1) {
		int a, b, c;
		tie(c, a, b) = edge[i++];
		if (find(a) == find(b))
			continue;
		parent[find(a)] = find(parent[b]);
		connect++;
		cost += c;
	}

	cout << cost;
}