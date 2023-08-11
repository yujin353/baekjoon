#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<bool> visited(max(n,k) * 4, false);
	vector<int> time(max(n,k) * 4, INT_MAX);
	time[n] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, n));

	while(!pq.empty()) {
		int now = pq.top().second;
		int nowT = pq.top().first;
		pq.pop();

		if (visited[now]) continue;
		visited[now] = true;
		
		if (now == k) break;

		if (now > 0){
			int next = now - 1;
			if (visited[next] == false) {
				time[next] = min(time[next], nowT+1);
				pq.push(make_pair(time[next], next));
			}
		}
		if (now < max(n,k) * 4 - 1){
			int next = now + 1;
			if (visited[next] == false) {
				time[next] = min(time[next], nowT+1);
				pq.push(make_pair(time[next], next));
			}
		}

		if (now < max(n,k) * 2) {
			int next = now * 2;
			if (visited[next] == false) {
				time[next] = min(time[next], nowT);
				pq.push(make_pair(time[next], next));
			}
		}
	}

	cout << time[k] << "\n";
}