#include <bits/stdc++.h>

using namespace std;

int main() {
	int stick = 64;
	int X;
	scanf("%d", &X);
	
	int min = stick;
	int count = 1;
	while (stick != X) {
		min = min / 2;
		if (stick - min >= X) {
			stick -= min;
		}
		else {
			count++;
		}
	}
	printf("%d", count);
}
