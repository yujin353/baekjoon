#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;
vector<vector<int>> D;
vector<vector<int>> W;
static int INF = 16000001;

int tsp(int c, int v) {
	if (v == (1 << n)-1) { //��� ���� �湮
		if (W[c][0] == 0)
			return INF;
		else
			return W[c][0];
	}

	if (D[c][v] != 0) { //�̹� ������� �ִ� ���
		return D[c][v];
	}

	int minV = INF;
	for (int i = 0; i < n; i++) {
		if ((v & (1 << i)) == 0 && W[c][i] != 0) { //�湮�� �� ���� �� �� �ִ� ������ ���
			minV = min(minV, tsp(i, (v|(1<<i))) + W[c][i]);
		}
	}
	return D[c][v] = minV;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	W.resize(n); //���
	for (int i = 0; i < n; i++){
		W[i].resize(n);
		for (int j = 0; j < n; j++)
			cin >> W[i][j];
	}

	D.resize(n);
	for (int i = 0; i < n; i++)
		D[i].resize(1 << n, 0);

	cout << tsp(0, 1) << "\n";
}