#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int tmp;
	vector<int> answer(n,0);
	stack<pair<int,int>> s;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		while(!s.empty() && tmp > s.top().first){
			answer[s.top().second] = tmp;
			s.pop();
		}
		s.push(make_pair(tmp,i));
	}
	while(!s.empty()) {
		answer[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++)
		cout << answer[i] << " ";
}