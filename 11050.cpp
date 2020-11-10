#include <bits/stdc++.h>

using namespace std;

int F(int n) {
	if (n < 1) return 1;
	else return n * F(n - 1);
}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d", F(N) / (F(K) * F(N - K)));
}
