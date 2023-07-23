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
	for (int i = 0; i <= n + 100; i++) { // �������Ŭ�� ���ĵǵ��� ����� ū ���� �ݺ�
		for (int j = 0; j < m; j++) {
			int s,e,c;
			tie(s,e,c) = trf[j];
			if (cost[s] == LONG_MIN) continue; // ���۳�尡 �̹湮 ����̸� continue
			else if (cost[s] == LONG_MAX) // ���� ��尡 �������Ŭ�� ����� ����� ���� ��嵵 ���� ���� ����
				cost[e] = LONG_MAX;
			else if(cost[e] < cost[s] - c + earn[e]){// �� ���� ���� ���� �ִ� ���ο� ��ΰ� �߰ߵ� ��� ���ο� ��� ������ ����
				cost[e] = cost[s] - c + earn[e];
				if (i >= n - 1)
					cost[e] = LONG_MAX; // N-1 �ݺ� ���� ���ŵǴ� ���� ���� �������Ŭ ���� ���� ����
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