#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		int num;
		scanf(" %d", &num);
		arr[i] = num;
	}
	sort(arr, arr + N);
	
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		int lb = lower_bound(arr, arr + N, num) - arr;
		int ub = upper_bound(arr, arr + N, num) - arr;
		if (lb == ub) {
			printf("%d ", 0);
		}
		else {
			printf("%d ", ub - lb);
		}
	}
}
