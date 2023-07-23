#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, m, start, end;
	cin >> n >> start >> end >> m;

	typedef tuple<int, int, int> edge;
	vector<edge> trf(m);
	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		trf[i] = make_tuple(s,e,c);
	}

	vector<int> earn(n);
	for (int i = 0; i < n; i++)
		cin >> earn[i];

	vector<long long> cost(n, LONG_MIN);
	cost[start] = earn[start];

	bool nCycle = false;
	for (int i = 0; i <= n + 100; i++) { // 양수싸이클이 전파되도록 충분히 큰 수로 반복
		for (int j = 0; j < m; j++) {
			int s,e,c;
			tie(s,e,c) = trf[j];
			if (cost[s] == LONG_MIN) continue; // 시작노드가 미방문 노드이면 continue
			else if (cost[s] == LONG_MAX) // 시작 노드가 양수사이클에 연결된 노드라면 종료 노드도 연결 노드로 갱신
				cost[e] = LONG_MAX;
			else if(cost[e] < cost[s] - c + earn[e]){// 더 많은 돈을 벌수 있는 새로운 경로가 발견된 경우 새로운 경로 값으로 갱신
				cost[e] = cost[s] - c + earn[e];
				if (i >= n - 1)
					cost[e] = LONG_MAX; // N-1 반복 이후 갱신되는 종료 노드는 양수사이클 연결 노드로 변경
			}
		}
	}

	if (cost[end] == LONG_MIN)
		cout << "gg" << "\n";
	else{
		if (cost[end] == LONG_MAX)
			cout << "Gee" << "\n";
		else
			cout << cost[end] << "\n";
	}
}