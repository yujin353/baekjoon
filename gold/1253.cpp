#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());

	int i = 0, j = n-1, target = 0, cnt = 0;
	while(i < n && j < n && target < n) {
		if (num[i] + num[j] == num[target] && i != target && j != target && i != j){
			cnt++;
			target++;
			i = 0;
			j = n-1;
		}
		else if (num[i] + num[j] < num[target]){
			i++;
		}
		else if (num[i] + num[j] > num[target]){
			j--;
		}
		if (i == target)
			i++;
		if(j == target)
			j--;
		if (i >= j) {
			target++;
			i = 0;
			j = n-1;
		}
	}
	cout << cnt;
}