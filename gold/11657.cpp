#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	typedef tuple<long long, long long, long long> edge;
	vector<edge> connect(m);
	for (int i = 0; i < m; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		connect[i] = make_tuple(a,b,c);
	}

	vector<long long> time(n+1, INT_MAX);
	time[1] = 0;

	for (int i = 0; i < n-1 ; i++) {
		for (int j = 0; j < m; j++) {
			long long a,b,c;
			tie(a,b,c) = connect[j];
			if (time[a] != INT_MAX && time[b] > time[a] + c) {
				time[b] = time[a] + c;
			}
		}
	}

	vector<long long> dupTime(n+1);
	for (int i = 2; i <= n; i++) 
		dupTime[i] = time[i];

	for (int j = 0; j < m; j++) {
		long long a,b,c;
		tie(a,b,c) = connect[j];
		if (time[a] != INT_MAX && time[b] > time[a] + c) {
			time[b] = time[a] + c;
		}
	}

	vector<int> answer(n+1);
	bool is_neg = false;
	for (int i = 2; i <= n; i++) {
		if (time[i] != dupTime[i]){
			is_neg = true;
			break;
		}
		if (time[i] == INT_MAX)
			answer[i] = -1;
		else
			answer[i] = time[i];
	}

	if (is_neg)
		cout << -1 << "\n";
	else
		for (int i = 2; i <= n; i++)
			cout << answer[i] << "\n";
}