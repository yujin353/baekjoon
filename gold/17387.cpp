#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef struct Point {
	ll x, y;
};

typedef struct Line {
	Point p1, p2;
};

Line line[2];

ll ccw(Point A, Point B, Point C) {
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

bool cross() {
	ll ab = ccw(line[0].p1, line[0].p2, line[1].p1) * ccw(line[0].p1, line[0].p2, line[1].p2);
	ll cd = ccw(line[1].p1, line[1].p2, line[0].p1) * ccw(line[1].p1, line[1].p2, line[0].p2);

	if (ab == 0 && cd == 0) { //일직선 상에 있는 경우 예외 처리
		return isOverlab(line[0], line[1]);
	}
	else
		return (ab <= 0 && cd <= 0); // ccw곱 둘다 음수면 교차점 존재
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 2; i++)
		cin >> line[i].p1.x >> line[i].p1.y >> line[i].p2.x >> line[i].p2.y;

	if (cross())
		cout << 1;
	else
		cout << 0;
}