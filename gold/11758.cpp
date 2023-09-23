#include <iostream>
using namespace std;

typedef struct Point {
	int x, y;
};

Point p[3];

int ccw(Point p1, Point p2, Point p3) {
	int c = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
	if (c == 0)
		return 0;
	else if (c < 0)
		return -1;
	else
		return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 3; i++)
		cin >> p[i].x >> p[i].y;

	cout << ccw(p[0], p[1], p[2]);
}