#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	if (n == 0) cout << 0;
	else if (n == 1) cout << 1;
	else {
		long long a = 0, b = 1;
		long long ans;
		for (int i = 1; i < n; i++) {
			ans = a + b;
			a = b;
			b = ans;
		}
		cout << ans;
	}
}
