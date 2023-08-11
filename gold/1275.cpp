#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	int k = 1;
	while(k < n) {
		k *= 2;
	}
	k *= 2;

	vector<ll> num(k, 0);
	for (int i = 0; i < n; i++) {
		cin >> num[k/2 + i]; // leaf 채우기
	}

	for (int i = k/2-1; i >= 0; i--) {
		num[i] = num[2*i] + num[2*i+1]; // nonleaf 채우기
	}

	for (int i = 0; i < q; i++) {
		int x, y, a;
		ll b, SUM = 0;

		cin >> x >> y >> a >> b;
		if (x > y){
			int tmp = x;
			x = y;
			y = tmp;
		}

		// 구간합 구하기
		int s = x + k/2 - 1;
		int e = y + k/2 - 1;

		while (s <= e) {
			if (s % 2 == 1) {
				SUM += num[s];
				s++;
			}
			if (e % 2 == 0) {
				SUM += num[e];
				e--;
			}
			s /= 2;
			e /= 2;
		}
		cout << SUM << "\n";

		// 업데이트
		a = a + k/2 - 1;
		ll dif = b - num[a];

		while (a > 0) {
			num[a] += dif;
			a /= 2;
		}
	}
}