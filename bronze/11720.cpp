#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

	char tmp;
    int answer = 0;
    for (int i = 0; i < n; i++) {
		cin >> tmp;
		answer += tmp - 48;
    }
	cout << answer << endl;
}