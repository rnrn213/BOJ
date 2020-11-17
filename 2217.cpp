#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> ropes;
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int rope;
		cin >> rope;
		ropes.push_back(rope);
	}
	
	sort(ropes.begin(), ropes.end(), greater<int>());
	
	int w = 0, k = 0;
	for (auto rope: ropes) {
		k++;
		if (w <= k * rope) {
			w = k * rope;
		}
	}
	
	cout << w;
}
