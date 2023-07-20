#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> frd;
vector<bool> visited;
bool done = false;

void check_frd(int x, int depth) {
	if (depth == 5) {
		cout << 1;
		done = true;
		return;
	}

	for (int i = 0; i < frd[x].size(); i++){
		int next = frd[x][i];
		if (visited[next] == false){
			visited[next] = true;
			check_frd(next, depth + 1);
			visited[next] = false;
		}
		if (done)
			break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	frd.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		frd[a].push_back(b);
		frd[b].push_back(a);
	}

	visited.resize(n);
	int i = 0;
	while(!done && i < n) {
		for (int j = 0; j < n; j++)
			visited[j] = false;
		visited[i] = true;
		check_frd(i,1);
		i++;
	}

	if (!done)
		cout << 0;
}