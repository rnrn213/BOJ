#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	
	long long* sumArr = new long long[N];
	long long* numArr = new long long[N];
	vector<pair<int, long long>> diffArr;
	long long num, sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &num);
		sum += num;
		sumArr[i] = sum;
		numArr[i] = num;
	}
	
	int a, b, c;
	for (int i = 0; i < M + K; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			diffArr.push_back(make_pair(b, c - numArr[b - 1]));
			numArr[b - 1] = c;
		}
		else {
			long long result = sumArr[c - 1] - sumArr[b - 1] + numArr[b - 1];
			for (int i = 0; i < diffArr.size(); i++) {
				if (diffArr[i].first >= b && diffArr[i].first <= c) {
					if (diffArr[i].first == b) {
						result -= diffArr[i].second;
					}
					result += diffArr[i].second;
				}
			}
			printf("%lld\n", result);
		}
	}
}
