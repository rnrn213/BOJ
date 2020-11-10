#include <bits/stdc++.h>

using namespace std;

bool isValid(char* c) {
	bool v = true;
	stack<int> s;
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] == '(') {
			s.push(1);
		}
		else if (c[i] == '[') {
			s.push(2);
		}
		else if (c[i] == ')') {
			if (s.empty()) {
				v = false;
				break;
			}
			else if (s.top() != 1) {
				v = false;
				break;
			}
			else {
				s.pop();
			}
		}
		else if (c[i] == ']') {
			if (s.empty()) {
				v = false;
				break;
			}
			else if (s.top() != 2) {
				v = false;
				break;
			}
			else {
				s.pop();
			}
		}
	}
	return v;
}

int getVal(char* c, int a, int b) {
	int total = 0;
	if (b - a == 1) {
		return 1;
	}
	else {
		stack<int> s;
		int start = a + 1;
		for (int i = a + 1; i < b; i++) {
			if (c[i] == '(' || c[i] == '[') {
				s.push(1);
			}
			else if (c[i] == ')') {
				s.pop();
				if (s.empty()) {
					total += 2 * getVal(c, start, i);
					start = i + 1;
				}
			}
			else if (c[i] == ']') {
				s.pop();
				if (s.empty()) {
					total += 3 * getVal(c, start, i);
					start = i + 1;
				}
			}
		}
	}
	return total;
}

int main() {
	stack<int> s;
	char* c = new char[50];
	fgets(c, sizeof(char)*50, stdin);
	if (isValid(c)) {
		int total = getVal(c, -1, strlen(c) - 1);
		printf("%d", total);
	}
	else {
		printf("0");
	}
}
