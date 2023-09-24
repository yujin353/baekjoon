#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef struct Point {
	ll x, y;
};

ll ccw(Point A, Point B, Point C) {
	return (A.x * B.y + B.x * C.y + C.x * A.y) - (A.y * B.x + B.y * C.x + C.y * A.x);
}

vector<Point> p;
bool comp(Point A, Point B) {
	ll c = ccw(p[0], A, B);
	if (c == 0) {
		ll distA = (A.x - p[0].x) * (A.x - p[0].x) + (A.y - p[0].y) * (A.y - p[0].y);
		ll distB = (B.x - p[0].x) * (B.x - p[0].x) + (B.y - p[0].y) * (B.y - p[0].y);
		return (distA < distB);
	}
	return (c > 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	p.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		// Change ( point[0], x좌표가 가장 작은 점 中 y좌표가 제일 낮은 점 )
		if (i == 0) continue;
		if (p[i].x < p[0].x) {
			Point tmp = p[0];
			p[0] = p[i];
			p[i] = tmp;
		}
		else if (p[i].x == p[0].x) {
			if (p[i].y < p[0].y) {
				Point tmp = p[0];
				p[0] = p[i];
				p[i] = tmp;
			}
		}
	}

	// point[0]과의 극각도 순으로 정렬 (동일하면 거리가 가까운 점 우선)
	sort(next(p.begin()), p.end(), comp);
	/*for (int i = 0; i < n; i++)
		cout << p[i].x << " " << p[i].y << "\n";*/

	// convex Hull 구하기
	vector<Point> cH;
	cH.push_back(p[0]);
	cH.push_back(p[1]);
	for (int i = 2; i < n; i++) {
		while (cH.size() > 1 && ccw(cH[cH.size() - 2], cH.back(), p[i]) <= 0) {
			cH.pop_back();
		}
		cH.push_back(p[i]);
	}
	cout << cH.size();
}