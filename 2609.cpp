#include <bits/stdc++.h>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	
	int min = (A <= B) ? A : B;
	int max = (A > B) ? A : B;
	int gcm, lcm;
	for (int i = min; i > 0; i--) {
		if (A % i == 0 && B % i == 0) {
			gcm = i;
			break;
		}
	}
	for (int i = max; i <= A * B; i++) {
		if (i % A == 0 && i % B == 0) {
			lcm = i;
			break;
		}
	}
	cout << gcm << '\n' << lcm;
}
