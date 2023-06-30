#include <iostream>
using namespace std;

int main()
{
    int n;
    int cnt = 1;
    int start = 1;
    int end = 1;
    int accum = 0;
    
    cin >> n;
    while(start < n/2+1)
    {
        accum += end;
        if (accum > n)
        {
            start++;
            end = start;
            accum = 0;
        }
        else if (accum == n)
        {
            cnt++;
            start++;
            end = start;
            accum = 0;
        }
        else
        {
            end++;
        }
    }
    cout << cnt << endl;
}