#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	// 시간초과 방지
	cin.tie(NULL);					// 시간초과 방지
	cout.tie(NULL);					// 시간초과 방지

	int n, l;
	cin >> n >> l;

	int tmp;
	deque<pair<int, int>> myque;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		while (myque.size() && myque.back().second > tmp)
			myque.pop_back();
		
		myque.push_back(make_pair(i,tmp));

		if (myque.front().first <= i - l)
			myque.pop_front();
		
		cout << myque.front().second << ' ';
	}
}