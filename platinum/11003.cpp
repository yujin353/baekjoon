#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	// �ð��ʰ� ����
	cin.tie(NULL);					// �ð��ʰ� ����
	cout.tie(NULL);					// �ð��ʰ� ����

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