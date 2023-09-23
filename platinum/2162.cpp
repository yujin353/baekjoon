#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
typedef struct Point {
	int x, y;
};
typedef struct Line {
	Point p1, p2;
};

vector<Line> line;

int ccw(Point A, Point B, Point C) {
	ll result = (A.x * B.y + B.x * C.y + C.x * A.y) - (A.y * B.x + B.y * C.x + C.y * A.x);
	if (result < 0)
		return -1;
	else if (result > 0)
		return 1;
	else
		return 0;
}

bool isOverlab(Line A, Line B) {
	if (min(A.p1.x, A.p2.x) <= max(B.p1.x, B.p2.x) && min(B.p1.x, B.p2.x) <= max(A.p1.x, A.p2.x) && min(A.p1.y, A.p2.y) <= max(B.p1.y, B.p2.y) && min(B.p1.y, B.p2.y) <= max(A.p1.y, A.p2.y))
		return true;
	return false;
}

bool cross(Line A, Line B) {
	int ab = ccw(A.p1, A.p2, B.p1) * ccw(A.p1, A.p2, B.p2);
	int cd = ccw(B.p1, B.p2, A.p1) * ccw(B.p1, B.p2, A.p2);

	if (ab == 0 && cd == 0) {
		return isOverlab(A, B);
	}
	return (ab <= 0 && cd <= 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	line.resize(n);
	for (int i = 0; i < n; i++)
		cin >> line[i].p1.x >> line[i].p1.y >> line[i].p2.x >> line[i].p2.y;

	int group = 0, maxCnt = 0;
	vector<bool> included(n, false);
	for (int i = 0; i < n; i++) {
		if (included[i]) continue;
		included[i] = true;

		group++;
		int cnt = 0;

		queue<Line> q;
		q.push(line[i]);
		while (!q.empty()) {
			Line now = q.front();
			q.pop();
			cnt++;

			for (int j = i + 1; j < n; j++) {
				if (included[j]) continue;
				if (cross(now, line[j])) {
					q.push(line[j]);
					included[j] = true;
				}
			}
		}
		maxCnt = max(maxCnt, cnt);
	}

	cout << group << "\n" << maxCnt;
}