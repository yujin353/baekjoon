#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;

	vector<int> D(n+1);
	D[1] = 1;
	D[2] = 3;

	for (int i = 3; i <= n; i++)
		D[i] = (D[i-1] % 10007 + (D[i-2] * 2) % 10007)% 10007;

	cout << D[n] << "\n";
}