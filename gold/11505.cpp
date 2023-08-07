#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int size = 1;
	while (size < n)
		size *= 2;
	size *= 2;

	vector<long long> num(size, 1);
	for (int i = 0; i < n; i++){
		cin >> num[i+size/2]; // leaf node Ã¤¿ì±â
		num[i+size/2] %= 1000000007;
	}
	for (int i = size/2 - 1; i > 0; i--)
		num[i] = (num[2*i] % 1000000007) * (num[2*i+1] % 1000000007) % 1000000007;

	m += k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			int segNode = b + size/2 - 1;
			
			num[segNode] = c;
			segNode /= 2;

			while (segNode >= 1) {
				num[segNode] = (num[segNode * 2] % 1000000007) * (num[segNode * 2 + 1] % 1000000007) % 1000000007;
				segNode /= 2;
			}
		}
		else {
			int start = b + size/2 - 1;
			int end = c + size/2 - 1;
			long long answer = 1;
			while (start <= end) {
				if (start % 2 == 1) {
					answer *= num[start];
					answer %= 1000000007;
					start++;
				}
				if (end % 2 == 0) {
					answer *= num[end];
					answer %= 1000000007;
					end--;
				}
				start /= 2;
				end /= 2;
			}
			cout << answer << "\n";
		}
	}
}