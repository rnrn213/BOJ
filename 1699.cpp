#include <bits/stdc++.h>

using namespace std;

int arr[100001];

void init() {
	arr[0] = 0;
	arr[1] = 1;
	
	for (int i = 2; i <= 100000; i++) {
		int min = 100001;
		for (int j = sqrt(i); j > 0; j--) {
			if (j * j < i) {
				if (arr[i - j * j] < min) {
					min = 1 + arr[i - j * j];
				}
			}
			else {
				min = 1;
				break;
			}
		}
		arr[i] = min;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	
	int N;
	cin >> N;
	
	cout << arr[N];
}
