#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int l, c;
vector<string> alph;

void DFS(int idx, string x, int cnt_vow, int cnt_cons) {
	if (x.length() == l){
		if (cnt_vow >= 1 && cnt_cons >= 2)
			cout << x << "\n";
		return;
	}
	
	for (int i = idx+1; i < c; i++) {
		if (alph[i] == "a" || alph[i] == "e" || alph[i] == "i" || alph[i] == "o" || alph[i] == "u")
			DFS(i, x+alph[i], cnt_vow+1, cnt_cons);
		else
			DFS(i, x+alph[i], cnt_vow, cnt_cons+1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		string a;
		cin >> a;
		alph.push_back(a);
	}
	sort(alph.begin(), alph.end());
	
	for (int i = 0; i <= c - l; i++){
		int vow = 0, cons = 0;
		if (alph[i] == "a" || alph[i] == "e" || alph[i] == "i" || alph[i] == "o" || alph[i] == "u")
			vow++;
		else
			cons++;
		DFS(i, alph[i], vow, cons);
	}
}