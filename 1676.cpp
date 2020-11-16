#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	int count = 0;
	if (N >= 125) {
		count += (N / 125) * 3;
		count += (N / 25 - N / 125) * 2;
		count += (N / 5 - N / 25);
	}
	else if (N >= 25) {
		count += (N / 25) * 2;
		count += (N / 5 - N / 25);
	}
	else count += (N / 5);
	
	cout << count;
}
