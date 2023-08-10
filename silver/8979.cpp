#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;
struct P {
	int g, s, b, n;
};

bool comp(P A, P B) {
	if (A.g > B.g)
		return true;
	else if (A.g == B.g) {
		if (A.s > B.s)
			return true;
		else if (A.s == B.s) {
			if (A.b > B.b)
				return true;
			else if (A.b == B.b){
				if (A.n == k)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n >> k;

	vector<P> point(n+1);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cin >> point[num].g >> point[num].s >> point[num].b;
		point[num].n = num;
	}
	sort(point.begin(), point.end(), comp);

	int cnt = 1;
	for (int i = 0; i < n; i++)
		if (point[i].n != k)
			cnt++;
		else
			break;

	cout << cnt << "\n";
}