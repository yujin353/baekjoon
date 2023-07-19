#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	long answer = 0;
	vector<long> remainSum(n+1, 0); // 크기 N, 0으로 초기화
	vector<long> cntRemain(m+1, 0);

	int tmp;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		tmp %= m;
		remainSum[i] = (remainSum[i-1] + tmp) % m;
		cntRemain[remainSum[i]]++;
		if (remainSum[i] == 0)
			answer++;
	}

	for (int i = 0; i < m; i++) {
		if (cntRemain[i] > 0)
			answer += cntRemain[i] * (cntRemain[i] - 1) / 2;
	}

	cout << answer << "\n";
}