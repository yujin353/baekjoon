#include <iostream>
using namespace std;

int prime(int num)
{
	for (int i = 2; i < num; i++)
		if (num % i == 0)
			return 0;
	return 1;
}
int main()
{
    int m, n;
    cin >> m;
	cin >> n;

    for (int i = m; i <= n; i++)
		if (prime(i) == 1)
			cout << i << endl;
}