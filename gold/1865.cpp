#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;

	for (int tc = 0; tc < TC; tc++) {
		int n, m, w;
		cin >> n >> m >> w;

		vector<tuple<int,int,int>> edge;
		for (int i = 0; i < m; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			edge.push_back(make_tuple(s,e,t));
			edge.push_back(make_tuple(e,s,t));
		}
		for (int i = 0; i < w; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			edge.push_back(make_tuple(s,e,-t));
		}

		vector<int> D(n+1, 100000000);
		D[1] = 0; // 시작이 뭐든 음수 사이클만 존재하면 yes?니까 편하게 시작점 1로 고정

		bool cycleCheck = 0;
		for(int i = 0; i <= n; i++) {
			for (int j = 0; j < 2*m+w; j++) {
				int s,e,t;
				tie(s,e,t) = edge[j];
				if (D[e] > D[s] + t){
					D[e] = D[s] + t;
					if (i == n) {
						cycleCheck = 1;
					}
				}
			}
		}

		if (cycleCheck)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}