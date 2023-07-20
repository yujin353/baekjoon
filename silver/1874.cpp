#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); // 시간초과 방지
	cin.tie(NULL);		// 시간초과 방지
	cout.tie(NULL);		// 시간초과 방지

	int n;
	cin >> n;

	string pushpop;
	stack<int> s;
	int now;
	int idx = 1;
	for (int i = 1; i <= n; i++) {
		cin >> now;
		while (idx <= now) {
			s.push(idx);
			idx++;
			pushpop += '+';
		}
		while (!s.empty() && s.top() == now) {
			s.pop();
			pushpop += '-';
		}
	}

	if (pushpop.length() != 2 * n)
		cout << "NO";
	else
		for (int i = 0; i < 2 * n; i++)
			cout << pushpop[i] << "\n";		// 시간초과 방지
}