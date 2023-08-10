#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> D(n+1);
	for (int i = 0; i <= n; i++) {
		D[i].resize(10, 0);
	}
	D[1][0] = 0;
	for (int i = 1; i < 10; i++)
		D[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j >= 1)
				D[i][j] = (D[i][j] + D[i-1][j-1] % 1000000000) % 1000000000;
			if (j <= 8)
				D[i][j] = (D[i][j] + D[i-1][j+1] % 1000000000) % 1000000000;
		}
	}
		
	int answer = 0;
	for (int i = 0; i <= 9; i++)
		answer = (answer + D[n][i] % 1000000000) % 1000000000;
	
	cout << answer << "\n";
}