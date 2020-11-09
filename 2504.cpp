#include <bits/stdc++.h>

using namespace std;

int getVal(char* c, int a, int b) {
	if (b - a == 1) {
		if (c[a] == '(' && c[b] == ')') return 2;
		else return 3;
	}
	else {
		if (c[a] == '(' && c[b] == ')') return 2 * getVal(c, a + 1, b - 1);
		else return 3 * getVal(c, a + 1, b - 1);
	}
}

int main() {
	stack<int> s;
	char* c = new char[50];
	fgets(c, sizeof(char)*50, stdin);
	cout << strlen(c) << '\n';
	for (int i = 0; i< strlen(c); i++) {
	}
	cout << c[0] << " " << c[strlen(c) - 2] << " strlen(c) - 1: " << c[strlen(c) - 1];
}
