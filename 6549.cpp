#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	while (true) {
		priority_queue<long long> pq;
		int n;
		long long prevh, h, w;
		cin >> n;
		cout << "n = " << n << '\n';
		if (n == 0) break;
		
		cin >> prevh;
		w = 1;
		for (int i = 0; i < n - 1; i++) {
			cin >> h;
			if (prevh > h) {
				pq.push(prevh * w);
				cout << prevh * w << " pushed\n";
				prevh = h;
				w = 1;
			}
			else {
				w++;
			}
		}
		pq.push(prevh * w);
		cout << pq.top() << '\n';
	}
}
