#include <bits/stdc++.h>

using namespace std;

int main() {
	int T, PN;
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<long long> P = {0, 1, 1, 1, 2, 2};
		cin >> PN;
		if (PN == 1 || PN == 2 || PN == 3) cout << 1 << '\n';
		else if (PN == 4 || PN == 5) cout << 2 << '\n';
		else {
			long long a = P[1], b = P[5];
			long long ans;
			for (int j = 6; j <= PN; j++) {
				a = P[j - 5];
				b = P[j - 1];
				ans = a + b;
				P.push_back(ans);
			}
			cout << ans << '\n';
		}
	}
}
