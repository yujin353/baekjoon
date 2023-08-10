#include <iostream>
#include <vector>
using namespace std;
/* sol_1
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<vector<long long>> nCr(n+1);
	for (int i = 0; i <= n; i++){
		nCr[i].resize(n+1);
		nCr[i][i] = 1;
		nCr[i][0] = 1;
		nCr[i][1] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
		}
	}
	
	long long answer = 0;
	if (n % 2 == 0) {
		for (int i = 0; i <= n/2 - 1; i++) {
			answer += nCr[n-1-i][i];			
		}
	}
	else {
		for (int i = 0; i <= n/2; i++){
			answer += nCr[n-1-i][i];
		}
	}

	cout << answer << "\n";
}*/
int main() {
	int n;
	cin >> n;

	vector<vector<long long>> D(n+1);
	for (int i = 0; i <= n; i++)
		D[i].resize(2);

	D[1][0] = 0;
	D[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		D[i][0] = D[i-1][0] + D[i-1][1];
		D[i][1] = D[i-1][0];
	}
	
	cout << D[n][0] + D[n][1] << "\n";
}