#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> ingred(n);
	for (int i = 0; i < n; i++)
		cin >> ingred[i];
	sort(ingred.begin(), ingred.end());

	int s=0, e=n-1, cnt = 0;
	while (s < e) {
		if (ingred[s] + ingred[e] == m){
			cnt++;
			e--;
			s++;
		}
		else if (ingred[s] + ingred[e] > m){
			e--;
		}
		else
			s++;

	}
	cout << cnt;
}