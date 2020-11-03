#include <bits/stdc++.h>

using namespace std;

int main() {
	stack<int> s;
	
	int K, num;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num == 0) s.pop();
		else s.push(num);
	}
	
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
}
