#include <bits/stdc++.h>

using namespace std;

int getYear(int E, int S, int M) {
	int num = E - 1;
	while (true) {
		if (num % 28 == S - 1 && num % 19 == M - 1) break;
		else num += 15;
	}
	return num + 1;
}

int main() {
	int E, S ,M;
	scanf("%d %d %d", &E, &S, &M);
	printf("%d", getYear(E, S, M));
}
