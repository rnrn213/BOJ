#include <bits/stdc++.h>

using namespace std;

int Find(int arr[], int num) {
	if (arr[num] == num) return num;
	arr[num] = Find(arr, arr[num]);
	return arr[num];
}

void Union(int arr[], int a, int b) {
	a = Find(arr, a);
	b = Find(arr, b);
	if (a < b) arr[b] = a;
	else arr[a] = b;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	int* arr = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
		arr[i] = i;
	}
	
	int order, a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &order, &a, &b);
		
		if (order == 0) {
			Union(arr, a, b);
		}
		else {
			if (Find(arr, a) == Find(arr, b)) printf("YES\n");
			else printf("NO\n");
		}
	}
}
