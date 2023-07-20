#include <iostream>
#include <cmath>
using namespace std;

int prime[] = {2,3,5,7};
int add[] = {1,3,7,9};

bool is_prime(int x) {
	int sqr = int(sqrt(double(x)));
	for (int i = 2; i <= sqr; i++)
		if (x % i == 0)
			return false;
	return true;
}

void make_candi(int x, int len, int n) {
	if (len == 1 || is_prime(x)) {
		if (len == n){
			cout << x << "\n";
			return;
		}
		for (int i = 0; i < 4; i++) {
			make_candi(x * 10 + add[i], len+1, n);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < 4; i++) {
		make_candi(prime[i], 1, n);
	}
}