#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef struct Point {
	ll x, y;
};
typedef struct Line {
	Point p1, p2;
};

ld tri(Point A, Point B) {
	return (A.x * B.y) - (A.y * B.x);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<Point> polygon(n);
	for (int i = 0; i < n; i++) {
		cin >> polygon[i].x >> polygon[i].y;
	}

	ld area = 0.0;
	for (int i = 0; i < n - 1; i++) {
		area += tri(polygon[i], polygon[i + 1]);
	}
	area += tri(polygon[n - 1], polygon[0]); // 마지막과 처음점도 CCW 계산에 포함해주어야함

	cout << fixed;
	cout.precision(1);
	cout << abs(area) / 2.0;
}