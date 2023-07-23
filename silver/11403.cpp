#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> node(n);
	for (int i = 0; i < n; i++)
		node[i].resize(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> node[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (node[j][i] == 1 && node[i][k] == 1)
					node[j][k] = 1;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << node[i][j] << " ";
		cout << "\n";
	}
}