#include <bits/stdc++.h>

using namespace std;

int main() {
	queue<int> q;
	vector<int> ans;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	
	int count = 1;
	while (q.size() > 1) {
		if (count == K) {
			ans.push_back(q.front());
			q.pop();
			count = 1;
		}
		else {
			q.push(q.front());
			q.pop();
			count++;
		}
	}
	
	cout << "<";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ", ";
	}
	cout << q.front() << ">";
}
