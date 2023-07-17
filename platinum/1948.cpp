#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> connect;
	vector<vector<int>> time;
	vector<int> pointed;
	connect.resize(n+1);
	time.resize(n+1);
	pointed.resize(n+1);
	for (int i = 1; i <= n; i++) {
		time[i].resize(n+1);
	}

	vector<vector<int>> reverseConnect;
	reverseConnect.resize(n+1);

	int start, end, take;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> take;
		connect[start].push_back(end);
		time[start][end] = take;
		pointed[end]++;

		reverseConnect[end].push_back(start);
	}


	int startCity, endCity;
	cin >> startCity >> endCity;
	
	vector<int> accumTime;
	accumTime.resize(n+1);
	for(int i = 1; i <= n; i++) {
		accumTime[i] = 0;
	}

	// ���� ����
	queue<int> myqueue;
	myqueue.push(startCity);
	while(!myqueue.empty()) {
		int now = myqueue.front();
		myqueue.pop();
		for (int i = 0; i < connect[now].size(); i++) {
			int next = connect[now][i];
			pointed[next]--;
			accumTime[next] = max(accumTime[next], accumTime[now] + time[now][next]);
			if (pointed[next] == 0)
				myqueue.push(next);
		}
	}

	// ���� ���� reverse
	int cntRoad = 0;
	vector<bool> visited;
	visited.resize(n+1);
	visited[endCity] = true;
	myqueue.push(endCity);
	while(!myqueue.empty()) {
		int now = myqueue.front();
		myqueue.pop();
		for (int i = 0; i < reverseConnect[now].size(); i++) {
			int next = reverseConnect[now][i];
			
			if (accumTime[next] == accumTime[now] - time[next][now]){ // 1�е� ���� �ʴ� ���� üũ
				cntRoad++;
				if (visited[next] == false) { // �ߺ� ī��Ʈ ������ ���� �� �湮 ��� ����
					visited[next] = true;
					myqueue.push(next);
				}
			}
		}
	}
	
	cout << accumTime[endCity] << endl << cntRoad << endl;
}