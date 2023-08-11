#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> p;
int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	priority_queue<tuple<int, int, int>> road;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road.push(make_tuple(-c, a, b));
	}

	p.resize(n+1);
	for (int i = 1; i <= n; i++)
		p[i] = i;

	int answer = 0, cnt = 0;
	for (int i = 0; i < m; i++) {
		if (cnt == n-2)
			break;

		int a, b, c;
		tie(c, a, b) = road.top();
		road.pop();

		if (find(a) == find(b)) continue;
		p[find(a)] = find(p[b]);
		answer -= c;
		cnt++;
	}
	
	cout << answer << "\n";
}