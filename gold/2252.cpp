#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static vector<vector<int>> cmp;
static vector<int> pointed;

int main() {
	int n, m;
	cin >> n >> m;

	cmp.resize(n+1);
	pointed.resize(n+1);
	for (int i = 0; i <= n; i++) { // ÃÊ±âÈ­
		pointed[i] = 0;
		cmp[i].push_back(i);
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cmp[a].push_back(b);
		pointed[b]++;
	}

	queue<int> queue;
	for(int i = 1; i <= n; i++)
		if (pointed[i] == 0)
			queue.push(i);

	while (!queue.empty()) {
		int now = queue.front();
		queue.pop();
		cout << now << " ";
		for (int j = 0; j < cmp[now].size(); j++) {
			pointed[cmp[now][j]]--;
			if (pointed[cmp[now][j]] == 0)
				queue.push(cmp[now][j]);
		}
	}
}