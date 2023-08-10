#include <iostream>
#include <vector>
using namespace std;
/* sol_1
int main() {
	int n;
	cin >> n;

	vector<vector<int>> nCr(n+1);
	
	for (int i = 0; i <= n; i++) {
		nCr[i].resize(n+1);
		nCr[i][i] = 1;
		nCr[i][0] = 1;
		nCr[i][1] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			nCr[i][j] = ((nCr[i-1][j-1] % 10007) + (nCr[i-1][j] % 10007)) % 10007;
		}
	}
	
	int answer = 0;
	for (int i = 0; i <= n/2; i++)
		answer = (answer + nCr[n-i][i] % 10007) % 10007;

	cout << answer << "\n";
}*/
int main() {
	int n;
	cin >> n;

	vector<int> D(n+1);
	D[1] = 1;
	D[2] = 2;

	for (int i = 3; i <= n; i++)
		D[i] = (D[i-1] % 10007 + D[i-2] % 10007)% 10007;

	cout << D[n] << "\n";
}