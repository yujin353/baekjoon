#include <iostream>
using namespace std;

bool truth[51];
/*int connect[51];

int find(int x){
	if (connect[x] == x)
		return x;

	connect[x] = find(connect[x]);

	if (truth[connect[x]])
		truth[x] = true;
	else if (truth[x])
		truth[connect[x]] = true;

	return connect[x];
}*/

int main() {
	int n, m;
	cin >> n >> m; // 사람 수, 파티 수

	for (int i = 0; i < n; i++){ // 초기화
		//connect[i] = i;
		truth[i] = false;
	}

	int know;
	cin >> know;
	int tmp;
	for (int i = 0; i < know; i++) {
		cin >> tmp;
		truth[tmp] = true;
	}

	int come[51];
	int pNum[51];
	int party[51][51];
	for (int i = 0; i < m; i++){
		cin >> come[i];
		for (int j = 0; j < come[i]; j++){
			cin >> pNum[j];
			party[i][j] = pNum[j];
			//connect[pNum[j]] = find(connect[pNum[0]]);
		}
	}

	for (int i = 0; i < m; i++) {
		bool exist = false;
		for (int j = 0; j < come[i]; j++) {
			if (truth[party[i][j]]) {
				exist = true;
				break;
			}
		}
		if (exist)
			for (int j = 0; j < come[i]; j++)
				truth[party[i][j]] = true;
	}

	for (int k = 0; k < m; k++) {
		for (int i = 0; i < m; i++) {
			bool exist = false;
			for (int j = 0; j < come[i]; j++) {
				if (truth[party[i][j]]) {
					exist = true;
					break;
				}
			}
			if (exist)
				for (int j = 0; j < come[i]; j++)
					truth[party[i][j]] = true;
		}
	}

	int cnt = 0;
	bool answer;
	for (int i = 0; i < m; i++) {
		answer = true;
		for (int j = 0; j < come[i]; j++) {
			if (truth[party[i][j]]) {
				answer = false;
				break;
			}
		}
		if (answer)
			cnt++;
	}

	cout << cnt << endl;
}