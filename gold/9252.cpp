#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	int len1 = s1.length();
	int len2 = s2.length();

	vector<vector<int>> cnt(len1+1);
	for (int i = 0; i <= len1; i++)
		cnt[i].resize(len2+1, 0);

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (s1[i-1] == s2[j-1])
				cnt[i][j] = cnt[i-1][j-1] + 1;
			else
				cnt[i][j] = max(cnt[i-1][j], cnt[i][j-1]);
		}
	}
	cout << cnt[len1][len2] << "\n";

	if (cnt[len1][len2] != 0) {
		string lcs = "";

		int i = len1, j = len2;
		while(i >= 1 && j >= 1) {
			if (s1[i-1] == s2[j-1]) {
				lcs += s1[i-1];
				i--;
				j--;
			}
			else {
				if (cnt[i-1][j] > cnt[i][j-1])
					i--;
				else
					j--;
			}
		}

		for (int i = lcs.length()-1; i >= 0; i--)
			cout << lcs[i];
	}
}