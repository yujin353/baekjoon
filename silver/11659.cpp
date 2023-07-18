#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	// �ð� �ʰ� ���� ����
	cin.tie(NULL);					// �ð� �ʰ� ���� ����
	cout.tie(NULL);					// �ð� �ʰ� ���� ����

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
		cout << s[b] - s[a-1] << '\n';	// endl�� �ϸ� �ð� �ʰ�;
	}
}