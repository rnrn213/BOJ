#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	int count = 0;
	while (N != 0) {
		cout << N << " - " << pow(static_cast<int>(sqrt(N)), 2) << '\n';
		N -= pow(static_cast<int>(sqrt(N)), 2);
		count++;
	}
	cout << count;
}
