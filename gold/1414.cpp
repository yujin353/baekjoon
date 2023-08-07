#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> parent;

int find(int x) {
	if (x == parent[x])
		return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, tot = 0;
	cin >> n;

	vector<vector<int>> lan(n);
	for(int i = 0; i < n; i++) {
		lan[i].resize(n);
		string tmp;
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			if (tmp[j] == '0')
				lan[i][j] = 0;
			else if (tmp[j] >= 97)//a == 97, A == 65
				lan[i][j] = tmp[j] - 96;
			else
				lan[i][j] = tmp[j] - 38;
			tot += lan[i][j];
		}
	}
	
	vector<tuple<int,int,int>> shortLan;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (lan[i][j] == 0 && lan[j][i] == 0) continue;

			if (lan[i][j] > lan[j][i]){
				if (lan[j][i] == 0)
					shortLan.push_back(make_tuple(lan[i][j], i, j));
				else
					shortLan.push_back(make_tuple(lan[j][i], i, j));
			}
			else {
				if (lan[i][j] == 0)
					shortLan.push_back(make_tuple(lan[j][i], i, j));
				else 
					shortLan.push_back(make_tuple(lan[i][j], i, j));
			}
		}
	}
	sort(shortLan.begin(), shortLan.end());

	parent.resize(n);
	for (int i = 0; i < n; i++)
		parent[i] = i;
	
	int need = 0, connect = 0, idx = 0;
	while(connect < n - 1 && idx < shortLan.size()) {
		int a, b, c;
		tie(a,b,c) = shortLan[idx++];
		if (find(b) == find(c)) continue;
		parent[find(b)] = find(c);
		need += a;
		connect++;
	}

	if (connect == n-1)
		cout << tot - need;
	else
		cout << -1;
}