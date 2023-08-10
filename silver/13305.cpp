#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> dist(n-1);
	for (int i = 0; i < n - 1; i++) {
		cin >> dist[i];
	}
	vector<int> cost(n);
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	// �� �ڿ����� �������� �������� Ȯ���� �������� �޸���ŭ ��α�
	long long answer = 0, d = dist[0];
	int start = 0;
	for (int i = 1; i <= n-1; i++){
		if (cost[start] > cost[i] || i == n-1){
			answer += d * cost[start];
			start = i;
			if (i < n-1)
				d = dist[i];
		}
		else {
			d += dist[i];
		}
	}	

	cout << answer;
}