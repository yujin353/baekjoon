#include <iostream>
using namespace std;
int connect[201];

int find(int x) {
	if (connect[x] == x)
		return x;

	connect[x] = find(connect[x]);
	return connect[x];
}

int main() {
	int n, m, tmp;
	//int connect[201];
	int course[1001];
	cin >> n; // 도시 수
	cin >> m; // 여행 계획 수

	for (int i = 0; i <= n; i++)
		connect[i] = i;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp == 1) {
				connect[find(i+1)] = find(connect[j+1]);
			}
		}
	}

	for (int i = 0; i < m; i++){
		cin >> course[i];
	}

	bool answer = true;
	for (int i = 0; i < m-1; i++) {
		if (find(course[i]) !=  find(course[i+1])) {
			cout << "NO" << endl;
			answer = false;
			break;
		}
	}
	if (answer)
		cout << "YES" << endl;

}