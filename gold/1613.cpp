#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, s;
	cin >> n >> k;

	vector<vector<int>> connect(n+1);
	for (int i = 1; i <= n; i++) {
		connect[i].resize(n+1, 0);
	}

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		connect[a][b] = -1;
		connect[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (connect[s][k] == -1 && connect[k][e] == -1)
					connect[s][e] = -1;
				else if (connect[s][k] == 1 && connect[k][e] == 1)
			#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, s;
	cin >> n >> k;

	vector<vector<int>> connect(n+1);
	for (int i = 1; i <= n; i++) {
		connect[i].resize(n+1, 0);
	}

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		connect[a][b] = -1;
		connect[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (connect[s][k] == -1 && connect[k][e] == -1)
					connect[s][e] = -1;
				else if (connect[s][k] == 1 && connect[k][e] == 1)
					connect[s][e] = 1;
			}
		}
	}

	cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;

		if (connect[a][b] == -1)
			cout << -1 << "\n";
		else if (connect[a][b] == 0)
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
		
	}
}		connect[s][e] = 1;
			}
		}
	}

	cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;

		if (connect[a][b] == -1)
			cout << -1 << "\n";
		else if (connect[a][b] == 0)
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
		
	}
}