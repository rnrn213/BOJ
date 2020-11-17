#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

bool isPrime(int n) {
	bool p = true;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			p = false;
			break;
		}
	}
	return p;
}

void f(int N) {
	for (int i = 2; i <= N; i++) {
		while (N % i == 0 && isPrime(i)) {
			N /= i;
			ans.push_back(i);
		}
	}
}

void printAns() {
	for (auto a: ans) {
		cout << a << '\n';
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	f(N);
	
	printAns();
}
