#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Pic {
	int num, cnt, time;
	Pic(int _num, int _cnt, int _time) : num(_num), cnt(_cnt), time(_time) {}
};

struct comp {
	bool operator()(const Pic& A, const Pic& B) {
		if (A.cnt > B.cnt)
			return true;
		else if (A.cnt == B.cnt)
			return A.time > B.time;
		return false;
	}
};

int main() {
	int n, recom;
	cin >> n >> recom;

	priority_queue<Pic, vector<Pic>, comp> pq;
	priority_queue<Pic, vector<Pic>, comp> dup_pq;
	for (int i = 0; i < recom; i++) {
		int tmp;
		cin >> tmp;

		if (i % 2 == 0) {
			bool exist = false;
			while(!dup_pq.empty()) {
				int cnt = dup_pq.top().cnt;
				int num = dup_pq.top().num;
				int time = dup_pq.top().time;

				if (tmp == num) {
					exist = true;
					cnt++;
				}
				dup_pq.pop();
				pq.push(Pic(num, cnt, time));
			}
			if (!exist && pq.size() == n) {
				pq.pop();
			}
			if (!exist)
				pq.push(Pic(tmp, 1, i));

		}
		else {
			bool exist = false;
			while (!pq.empty()) {
				int cnt = pq.top().cnt;
				int num = pq.top().num;
				int time = pq.top().time;

				if (tmp == num) {
					exist = true;
					cnt++;
				}
				pq.pop();
				dup_pq.push(Pic(num, cnt, time));
			}

			if (!exist && dup_pq.size() == n) {
				dup_pq.pop();
			}

			if (!exist)
				dup_pq.push(Pic(tmp, 1, i));

		}
	}

	vector<int> answer;
	if (pq.empty()) {
		while(!dup_pq.empty()) {
			answer.push_back(dup_pq.top().num);
			dup_pq.pop();
		}
	}
	else {
		while(!pq.empty())  {
			answer.push_back(pq.top().num);
			pq.pop();
		}
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
}