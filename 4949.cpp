#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		stack<int> s;
		bool isBalanced = true;
		char* temp = new char[102];
		fgets(temp, sizeof(char)*102, stdin);
		//temp[strlen(temp)] = NULL;
		for (int i = 0; i < strlen(temp); i++) {
			//printf("%c", temp[i]);
			
			if (temp[i] == '(') s.push(1);
			else if (temp[i] == '[') s.push(2);
			else if (temp[i] == ')') {
				if (s.empty()) isBalanced = false;
				else if (s.top() != 1) isBalanced = false;
				else s.pop();
			}
			else if (temp[i] == ']') {
				if (s.empty()) isBalanced = false;
				else if (s.top() != 2) isBalanced = false;
				else s.pop();
			}
		}
		//cout << '\n';
		if (temp[0] == '.' && strlen(temp) == 2) {
			break;
		}
		else {
			if (isBalanced && s.empty()) printf("yes\n");
			else printf("no\n");
		}
	}
}
