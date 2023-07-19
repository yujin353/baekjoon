#include <iostream>
#include <vector>
using namespace std;

int main() {
	int s, p;
	cin >> s >> p;

	vector<char> dna(s);
	for (int i = 0; i < s; i++){
		cin >> dna[i];
	}
	
	vector<int> acgt(4);
	for (int i = 0; i < 4; i++){
		cin >> acgt[i];
	}

	int cntA = 0;
	int cntC = 0;
	int cntG = 0;
	int cntT = 0;
	for (int i = 0; i < p; i++) {
		if (dna[i] == 'A')
			cntA++;
		else if (dna[i] == 'C')
			cntC++;
		else if (dna[i] == 'G')
			cntG++;
		else if (dna[i] == 'T')
			cntT++;
	}

	int answer = 0;
	if (cntA >= acgt[0] && cntC >= acgt[1] && cntG >= acgt[2] && cntT >= acgt[3])
		answer++;

	for (int i = p; i < s; i++) {
		if (dna[i] == 'A')
			cntA++;
		else if (dna[i] == 'C')
			cntC++;
		else if (dna[i] == 'G')
			cntG++;
		else if (dna[i] == 'T')
			cntT++;

		if (dna[i-p] == 'A')
			cntA--;
		else if (dna[i-p] == 'C')
			cntC--;
		else if (dna[i-p] == 'G')
			cntG--;
		else if (dna[i-p] == 'T')
			cntT--;

		if (cntA >= acgt[0] && cntC >= acgt[1] && cntG >= acgt[2] && cntT >= acgt[3])
			answer++;
	}

	cout << answer;
}