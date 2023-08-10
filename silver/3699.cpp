#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct P {
	int high, leng;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int h, l;
		cin >> h >> l;

		int carCnt = 0;
		vector<P> car(h*l);
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < l; j++){
				int num;
				cin >> num;
				if (num != -1){
					car[num].high = i;
					car[num].leng = j;
					carCnt++;
				}
			}
		}

		vector<int> eachHighBeforeBelt(h, 0);

		int time = 0;
		for (int i = 1; i <= carCnt; i++) {
			time += car[i].high * 20;
			int minMove = min(car[i].leng + l - eachHighBeforeBelt[car[i].high], min(abs(car[i].leng - eachHighBeforeBelt[car[i].high]), eachHighBeforeBelt[car[i].high] + l - car[i].leng));
			time += minMove * 5;
			eachHighBeforeBelt[car[i].high] = car[i].leng;
		}

		cout << time << "\n";
	}
}