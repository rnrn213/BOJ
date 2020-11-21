// https://private-space.tistory.com/12 코드 참고

#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		stack<int> s;
		long long* h = new long long[n];
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		long long area = 0;
		for (int i = 0; i < n; i++) {
			while (!s.empty() && h[s.top()] >= h[i]) {
				int temp = s.top();
				s.pop();
				int w;
				if (s.empty()) w = i;
				else w = i - s.top() - 1;

				area = max(area, h[temp] * w);
			}
			s.push(i);
		}

		while (!s.empty()) {
			int temp = s.top();
			s.pop();
			int w = n;
			if (!s.empty()) {
				w -= s.top() + 1;
			}
			area = max(area, h[temp] * w);
		}
		cout << area << '\n';
	}
}
