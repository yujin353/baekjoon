#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	while (cin >> n) { // c++ �׽�Ʈ ���̽� ����  �Է� �ޱ�
		long long a = 1;
		int i = 1;
		while (a % n != 0) {
			a = a * 10 + 1;
			i++;
			a %= n;
		}
		cout << i << "\n";
	}
}