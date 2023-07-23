#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<int> unionFind;

int find(int x) {
	if (x == unionFind[x])
		return x;
	unionFind[x] = find(unionFind[x]);
	return unionFind[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;

	// 에지 리스트로 그래프 구현
	typedef tuple<long long,int,int> edge;
	priority_queue<edge, vector<edge>, greater<edge>> pq;
	for (int i = 0; i < E; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		pq.push(make_tuple(c, a, b));
	}

	// 유니온 파인드 배열 초기화
	unionFind.resize(V+1);
	for (int i = 1; i <= V; i++)
		unionFind[i] = i;

	int cnt_connectEdge = 0;
	long long accumWeight = 0;
	// 가중치가 낮은 에지부터 연결 시도
	for (int i = 0; i < E; i++) {
		int a, b;
		long long c;
		tie(c, a, b) = pq.top();
		pq.pop();
		
		if (find(a) != find(b)) { // 유니온파인드 이용해 사이클 확인
			unionFind[find(b)] = find(a);
			cnt_connectEdge++;
			accumWeight += c;
		}
		if (cnt_connectEdge == V-1)
			break;
	}

	cout << accumWeight << endl;
}