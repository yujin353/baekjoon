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

	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];

	int answer = num[0];
	vector<int> L(n, 0);
	L[0] = num[0];
	for (int i = 1; i < n; i++) {
		L[i] = max(L[i-1] + num[i], num[i]);
		answer = max(answer, L[i]); // 하나도 제거하지 않았을 때 최댓값
	}

	vector<int> R(n, 0);
	R[n-1] = num[n-1];
	for (int i = n-2; i >= 0; i--)
		R[i] = max(R[i+1] + num[i], num[i]);


	for (int i = 1; i < n-1; i++){
		int tmp = L[i-1] + R[i+1]; // i번째를 제거 했을때 값
		answer = max(answer, tmp);
	}

	cout << answer << "\n";
}