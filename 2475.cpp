#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	printf("%d", (static_cast<int>(pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2) + pow(e, 2))) % 10);
}
