#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	// 시간 초과 방지 위함
	cin.tie(NULL);					// 시간 초과 방지 위함
	cout.tie(NULL);					// 시간 초과 방지 위함

	int n, m;
	cin >> n >> m;

	vector<int> s;
	s.resize(n+1);
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		s[i] = s[i-1] + tmp;
	}

	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		cout << s[b] - s[a-1] << '\n';	// endl로 하면 시간 초과;
	}
}