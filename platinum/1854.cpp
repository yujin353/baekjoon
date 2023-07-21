#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<pair<int,int>>> load(n+1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		load[a].push_back(make_pair(b,c));
	}
	vector<priority_queue<int>> time(n+1);
	time[1].push(0);
	for (int i = 2; i <= n; i++)
		time[i].push(INT_MAX);

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push(make_pair(0,1));
	
	while(!pq.empty()) {
		int now_dis = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		for(int i = 0; i < load[now].size(); i++) {
			int next = load[now][i].first;
			if (time[next].size() == k){
				if (time[next].top() > now_dis + load[now][i].second) {
					time[next].pop(); // ���� ť���� Max�� �������� ���־����
					time[next].push(now_dis + load[now][i].second);
					pq.push(make_pair(now_dis + load[now][i].second, next));////top�� �ƴ϶� now_dis + load[now][i].second�� �־���� ��
				}
			}
			else if (time[next].size() < k){
				time[next].push(now_dis + load[now][i].second);
				pq.push(make_pair(now_dis + load[now][i].second, next));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (time[i].size() == k && time[i].top() != INT_MAX) // k��°�� ��ħ ó�� �ʱ�ȭ �� INT_MAX�� ��� �����������
			cout << time[i].top() << "\n";
		else 
			cout << -1 << "\n";
	}
}