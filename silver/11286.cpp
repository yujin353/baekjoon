#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<pair<int,int>> pq;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		if (tmp != 0) {
			pq.push(make_pair(abs(tmp) * -1, tmp * -1)); // 오름차순 정렬 위함
		}
		else {
			if (pq.empty())
				cout << "0" << "\n";
			else {
				cout << pq.top().second * -1 << "\n";
				pq.pop();
			}
		}
	}
}