#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int start = 1, end = 1, cnt = 0, sum = 1;
	while(start <= n && end <= n) {
		if (sum == n) {
			cnt++;
			end++;
			sum += end;
		}
		else if (sum > n){
			sum -= start;
			start++;
		}
		else {
			end++;
			sum += end;
		}
	}
	cout << cnt << endl;
}