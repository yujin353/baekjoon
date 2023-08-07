#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int size = 1;
	while (size < n) {
		size *= 2;
	}
	size *= 2;

	vector<int> num(size, INT_MAX);
	for (int i = 0; i < n; i++) {
		cin >> num[i + size/2]; //leaf 초기화
	}
	for (int i = size/2-1; i > 0; i--)
		num[i] = min(num[2*i], num[2*i+1]); //nonleaf 초기화

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		int start = a + size/2 - 1;
		int end = b + size/2 - 1;

		int answer = INT_MAX;
		while (start <= end) {
			if (start % 2 == 1){
				answer = min(answer, num[start]);
				start++;
			}
			if (end % 2 == 0){
				answer = min(answer, num[end]);
				end--;
			}
			//cout << start << " " << end << " " << answer << "\n";
			start /= 2;
			end /= 2;
		}
		cout << answer << "\n";
	}

}