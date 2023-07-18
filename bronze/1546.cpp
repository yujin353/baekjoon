#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

	int tmp;
	long max = 0;
	long total = 0;
    for (int i = 0; i < n; i++) {
		cin >> tmp;
		total += tmp;
		if (tmp > max)
			max = tmp;
    }
	double new_avg = total * 100.0 / max / n;
	cout << new_avg << endl;
}