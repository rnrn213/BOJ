#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int A, B;
		cin >> A >> B;
		int min = (A < B) ? A : B;
		int gcm;
		for (int j = min; j >0; j--) {
			if (A % j == 0 && B % j ==0) {
				gcm = j;
				break;
			}
		}
		long long lcm = (A / gcm) * (B / gcm) * gcm;
		cout << lcm << '\n';
	}
}
