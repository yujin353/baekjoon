#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n, j;
	cin >> n;

	int time[501];
	int pointed[501];
	int totalTime[501];
	vector<vector<int>> before;
	before.resize(n+1);

	for (int i = 1; i <= n; i++) {
		cin >> time[i];
		totalTime[i] = 0;

		j = 0;
		while(1) {
			int tmp;
			cin >> tmp;
			if (tmp == -1)
				break;
			before[tmp].push_back(i);
			j++;
		}
		pointed[i] = j;
	}

	queue<int> queue;
	for (int i = 1; i <= n; i++) {
		if (pointed[i] == 0)
			queue.push(i);
	}

	while(!queue.empty()) {
		int now = queue.front();
		queue.pop();
		for (int i = 0; i < before[now].size(); i++) {
			int next = before[now][i];
			pointed[next]--;
			totalTime[next] = max(totalTime[next], totalTime[now] + time[now]);
			if (pointed[before[now][i]] == 0)
				queue.push(before[now][i]);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << totalTime[i] + time[i] << endl;
	}
}