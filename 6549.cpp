#include <bits/stdc++.h>

using namespace std;

long long getArea(const vector<long long>& v, int index) {
	long long h = v[index];
	long long area = h;
	long long min = h;
	bool decrease = false;
	bool isRect = true;
	if (h == 1) return 1;
	int w = 1;
	for (int i = index + 1; i < v.size(); i++) {
		if (!isRect) return area;
		w++;
		if (v[i] >= h) {
			if (decrease) isRect = false;
			if (isRect) area = w * h;
		}
		else {
			decrease = true;
			if (min > v[i]) {
				min = v[i];
			}
			else if (min < v[i]) {
				isRect = false;
			}

			if (area < w * v[i] && isRect) {
				area = w * v[i];
			}
		}
	}
	return area;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	while (true) {
		priority_queue<long long> pq;
		vector<long long> v;
		int n;
		cin >> n;
		if (n == 0) break;
		long long max = n;

		for (int i = 0; i < n; i++) {
			long long h;
			cin >> h;
			v.push_back(h);
		}

		for (int i = 0; i < v.size(); i++) {
			long long area = getArea(v, i);
			max = (max > area) ? max : area;
		}
		
		cout << max << '\n';
	}
}
