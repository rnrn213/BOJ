#include <bits/stdc++.h>

using namespace std;

int main() {
	priority_queue< long long, vector<long long> > pq;
	
	int N;
	long long x;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %lld", &x);
		if (x == 0) {
			if (!pq.empty()) {
				printf("%lld\n", pq.top());
				pq.pop();
			}
			else {
				printf("0\n");
			}
		}
		else {
			pq.push(x);
		}
	}
}
