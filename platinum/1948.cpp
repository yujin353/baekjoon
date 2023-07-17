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

	// 위상 정렬
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

	// 위상 정렬 reverse
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
			
			if (accumTime[next] == accumTime[now] - time[next][now]){ // 1분도 쉬지 않는 도로 체크
				cntRoad++;
				if (visited[next] == false) { // 중복 카운트 방지를 위해 기 방문 노드 제외
					visited[next] = true;
					myqueue.push(next);
				}
			}
		}
	}
	
	cout << accumTime[endCity] << endl << cntRoad << endl;
}