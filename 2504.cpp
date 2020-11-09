#include <bits/stdc++.h>

using namespace std;

int getVal(char* c, int a, int b) {
	if (b - a == 1) {
		if (c[a] == '(' && c[b] == ')') return 2;
		else return 3;
	}
	else {
		stack<int> s;
		int start = a + 1;
		int total = 0;
		for (int i = a + 1; i < b; i++) {
			if (c[i] == '(' || c[i] == '[') {
				s.push(1);
			}
			else if (c[i] == ')' || c[i] == ']') {
				s.pop();
			}
			if (s.empty()) {
				total += getVal(c, start, i);
				if (i != b - 1) start = i + 1;
			}
		}
	}
}

int main() {
	stack<int> s;
	char* c = new char[50];
	fgets(c, sizeof(char)*50, stdin);
	cout << strlen(c) << '\n';
	int total = 0, start = 0;
	for (int i = 0; i< strlen(c); i++) {
		if (c[i] == '(' || c[i] == '[') {
			s.push(1);
		}
		else if (c[i] == ')' || c[i] == ']') {
				s.pop();
		}
		if (s.empty()) {
			total += getVal(c, start, i);
			if (i != strlen(c) - 1) start = i + 1;
		}	
	}
	cout << total;
}
