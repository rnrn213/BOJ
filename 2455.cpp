#include <bits/stdc++.h>

using namespace std;

int main() {
	int num = 0, a = 0, b = 0, max = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &a, &b);
		num -= a;
		num += b;
		if (num > max) max = num;
	}
	printf("%d", max);
}
